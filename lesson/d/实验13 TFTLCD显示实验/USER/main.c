#include "led.h"      // LED与显示相关的头文件
#include "delay.h"    // 延迟功能的头文件
#include "sys.h"      // 系统配置与应用相关的头文件
#include "usart.h"    // 上位机传输口的头文件
#include "timer.h"    // 定时器功能的头文件
#include "key.h"      // 按键功能的头文件
#include "lcd.h"      // LCD显示功能的头文件
#include <string.h>    // C 库存下字符串功能的头文件

// 定义不同的命令类型
#define START 1         // 开始计时
#define PAUSE 2         // 暂停计时
#define STOP 3          // 自然计时结束命令
#define PRE_STOP 4      // 提前终止计时命令

// 按键功能定义
// KEY0_PRES 开始计时
// KEY1_PRES 暂停计时
// KEY2_PRES 终止计时

uint8_t have_time_flag=0; // 用于记录计时状态的标志使用的变量
uint8_t cmd=0;			// 0为无效命令的初始化值，状态控制标志位
uint8_t cmd_show_lcd=0;   // lcd窗口显示标志位
uint8_t cnt10=0,key=0; // 用于计时和按键信息的变量
uint8_t low=0,cnt=0;

// 定义时间结构体，用于记录计时的分钟，秒，百毫秒
struct Time
{
    uint8_t min;   // 分钟
    uint8_t sec;   // 秒
    uint8_t hmsec; // 百毫秒
} time; // 当前计时的时间结构体实例

// 功能声明
void Capture_cmd(void);        // 采集用户输入的命令
void time_capture(void);       // 采集用户输入的时间
void Sub_time(struct Time *time); // 时间減一的功能
void Update_LCD_Display(void); // 更新LCD显示

// 主函数
int main(void)
{   
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 设置中断优先级分组为2
    uart_init(115200); // 上位机传输速率设置为115200
    delay_init(); // 延迟功能初始化
    LED_Init();  // LED初始化
    KEY_Init();  // 按键初始化
    TIM3_Int_Init(1000-1,7200-1); // 设置TIM3为100ms中断一次
//    TIM2_Int_Init(10000-1,3600-1); // 设置TIM2为500ms中断一次

    LED0=0; // LED0光应初始化为点亮
    LCD_Init(); // LCD初始化
    POINT_COLOR=RED;  // LCD为红色文字
    LCD_Clear(WHITE); // LCD清屏，设置背景为白色
    LCD_ShowString(30, 40, 200, 24, 24,(u8 *)"Time :00:00:0"); // 显示初始时间
    LCD_ShowString(30, 80, 200, 24, 24,(u8 *)"State:input"); // 显示计时状态为输入

    printf("初始化成功\r\n"); // 向上位机发送初始化成功的提示

    // 主循环，进入时间计时的主逻辑
    while(1)
    {
        if(have_time_flag==0) // 无计时时间被设置
        {
            printf("请设置倒计时时间（格式 xx:xx:x 如01:59:8表示1分59秒8）\r\n"); // 请求输入起始计时时间
            while(have_time_flag==0)
            {
                time_capture(); // 请求用户输入计时的主函数
            }
            LCD_Clear(WHITE); // LCD设置为白色
            LED0=1; // LED0熄灭，表示计时设置成功
        }
        else // 已设置计时时间，持续捕获并执行命令
        {
            Capture_cmd(); // 捕获命令

            // 执行命令
            if(cmd==STOP) // 自然计时结束命令
            {
                printf("计时结束,可以重新设置计时时间\r\n");
                have_time_flag=0; // 重新开始捕获计时时间
                LED0=0; // LED0常亮
                cmd=0; // 重置命令
            }
            else if(cmd==PRE_STOP) // 提前终止命令
            {
                printf("终止计时\r\n可以重新设置计时时间\r\n");
                have_time_flag=0; // 重新开始捕获计时时间
                time.min=0;
                time.sec=0;
                time.hmsec=0;
                cnt10=0;
                LED0=1; // LED0熄灭
                cmd=0; // 重置命令
            }
            else if(cmd==PAUSE) // 暂停命令
            {
                LED0=0; // LED0常亮
                printf("计时已暂停，剩余计时时间：%02d:%02d:%d\r\n", time.min, time.sec, time.hmsec);
                printf("可以通过开始命令(start)继续计时\r\n");
                cmd=0; // 重置命令
            }
        }

        Update_LCD_Display(); // 更新LCD显示
    }    
}

// TIM3中断服务程序，100ms中断一次
void TIM3_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) // 检查TIM3中断是否发生
    {
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  // 清除TIM3中断标志
        if(cmd==START) // 开始计时，时间递减
        {
						 Sub_time(&time); // 时间递减
						cnt10++; // 计时10秒
					  cnt++;
					  cnt%=5;

					  if(cnt ==0)
					  {
						 LED0 = !LED0; // 1Hz闪烁
					  }
            
						cnt10 %= 100;
            if(cnt10 == 0 && low==time.hmsec) // 每10秒向上位机发送剩余计时时间
            {
                printf("剩余计时时间：%02d:%02d:%d\r\n", time.min, time.sec, time.hmsec);
            }

        }
    }
}

// TIM2中断服务程序，500ms中断一次
//void TIM2_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//    {
//        TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // 清除TIM2中断标志
//        if(cmd==START) // 开始计时，LED闪烁
//        {
//            cnt10++; // 计时10秒
//            cnt10 %= 20;
//            LED0 = !LED0; // 1Hz闪烁
//            if(cnt10 == 0) // 每10秒向上位机发送剩余计时时间
//            {
//                printf("剩余计时时间：%02d:%02d:%d\r\n", time.min, time.sec, time.hmsec);
//            }
//        }
//    }
//}

// 时间递减函数
void Sub_time(struct Time *time)
{
    if(time->hmsec > 0) // 百毫秒递减
    {
        time->hmsec--;
    }
    else if(time->sec > 0) // 如果百毫秒为0，秒递减
    {
        time->sec--;
        time->hmsec = 9; // 重置百毫秒
    }
    else if(time->min > 0) // 如果秒为0，分钟递减
    {
        time->min--;
        time->sec = 59; // 重置秒
        time->hmsec = 9; // 重置百毫秒
    }
    else // 如果分钟也为0，结束倒计时
    {
        cmd = STOP; // 自然计时结束命令
        cmd_show_lcd = cmd;
    }
}

// 捕获用户输入的倒计时时间
void time_capture(void)
{
    char time_str[10]; // 用于存储用户输入的时间字符串，例如 "01:59:8"
    uint8_t i = 0;
    if (USART_RX_STA & 0x8000) // 如果接收完成
    {
        // 将接收到的字符串从缓冲区复制到time_str
        while (i < 10 && (USART_RX_BUF[i] != '\0') && (USART_RX_BUF[i] != '\r') && (USART_RX_BUF[i] != '\n'))
        {
            time_str[i] = USART_RX_BUF[i];
            i++;
        }
        time_str[i] = '\0'; // 确保字符串结束

        // 解析时间字符串
        if (sscanf(time_str, "%2hhu:%2hhu:%hhu", &time.min, &time.sec, &time.hmsec) == 3)
        {
            // 合法检测
            if(time.min <= 59 && time.sec <= 59 && time.hmsec <= 9)
            {
                have_time_flag = 1; 
							  low = time.hmsec;
                printf("倒计时设置为: %02d:%02d:%d\r\n", time.min, time.sec, time.hmsec);
                printf("请选择命令：\r\nstart:开始计时\r\npause:停止计时\r\nstop:结束计时\r\n");
            }
            else // 不合法
            {
                have_time_flag = 0;
                printf("时间格式错误，请重新设置\r\n"); // 如果格式不正确，提示重新输入
            }
        }
        else // 如果格式不正确，提示重新输入
        {
            have_time_flag = 0;
            printf("时间格式错误，请重新设置\r\n");
        }
        USART_RX_STA = 0; // 重置接收标志，等待下次输入
        memset(USART_RX_BUF, 0, sizeof(USART_RX_BUF)); // 重置缓冲区
    }
}

// 捕获用户输入的命令
void Capture_cmd(void)
{
    char cmd_str[10]; // 用于存储命令字符串
    uint8_t i = 0;
    if (USART_RX_STA & 0x8000) // 捕获串口命令
    {
        // 将接收到的命令字符串从缓冲区复制到cmd_str
        while (i < 10 && (USART_RX_BUF[i] != '\0') && (USART_RX_BUF[i] != '\r') && (USART_RX_BUF[i] != '\n'))
        {
            cmd_str[i] = USART_RX_BUF[i];
            i++;
        }
        cmd_str[i] = '\0'; // 确保字符串结束

        // 解析并设置指令
        if (strcmp(cmd_str, "start") == 0)
        {
            cmd = START;
            cmd_show_lcd = cmd;
            printf("开始计时\r\n");
        }
        else if (strcmp(cmd_str, "pause") == 0)
        {
            cmd = PAUSE;
            cmd_show_lcd = cmd;
        }
        else if (strcmp(cmd_str, "stop") == 0)
        {
            cmd = PRE_STOP; // 提前结束计时命令
            cmd_show_lcd = cmd;
        }
        else // 如果指令不合法，提示重新输入
        {
            printf("命令错误，请重新输入\r\n");
        }
        USART_RX_STA = 0; // 重置接收标志，等待下次输入
        memset(USART_RX_BUF, 0, sizeof(USART_RX_BUF)); // 重置缓冲区
    }
    else // 捕获按键命令
    {
        key = KEY_Scan(0);
        if(key == KEY0_PRES)
        {
            cmd = PRE_STOP;
            cmd_show_lcd = cmd;
            printf("开始计时\r\n");
        }
        if(key == KEY1_PRES)
        {
            cmd = PAUSE;
            cmd_show_lcd = cmd;
        }                                                                                                                                                  
        if(key == KEY2_PRES)
        {
            cmd = START; // 提前结束计时命令
            cmd_show_lcd = cmd;
        }
    }
}

// 更新LCD显示的函数
void Update_LCD_Display(void)
{
    char time_str[12]; // 用于存储时间字符串，例如 "01:23:45"
    char state_str[10]; // 用于存储状态字符串，例如 "run"

    // 根据当前的计时状态来设置状态字符串
    if (cmd_show_lcd == START)
    {
        strcpy(state_str, "run  "); // 正在倒计时
    }
    else if (cmd_show_lcd == PAUSE)
    {
        strcpy(state_str, "pause"); // 暂停计时
    }
    else if (cmd_show_lcd == STOP || cmd_show_lcd == PRE_STOP)
    {
        strcpy(state_str, "stop "); // 计时结束
    }
    else
    {
        strcpy(state_str, "input"); // 默认状态，等待输入
    }

    // 格式化时间字符串为 "mm:ss:hm"
    sprintf(time_str, "%02d:%02d:%d", time.min, time.sec, time.hmsec);

    // 显示时间和状态
    LCD_ShowString(30, 40, 200, 24, 24, (u8 *)"Time :");
    LCD_ShowString(100, 40, 200, 24, 24, (u8 *)time_str); // 显示时间
    LCD_ShowString(30, 80, 200, 24, 24, (u8 *)"State:");
    LCD_ShowString(100, 80, 200, 24, 24, (u8 *)state_str); // 显示状态
}
