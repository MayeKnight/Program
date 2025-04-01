#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAXSIZE 100 // 顺序表的最大容量
#define ERROR 0
#define OK 1
typedef int Status;

// 图书信息结构体
struct Book
{
    int id;       // 图书编号
    string name;  // 图书名称
    double price; // 图书定价
};

// 顺序表结构体
struct SqList
{
    Book *elem; // 动态分配的存储空间基地址
    int length; // 顺序表当前长度
};

// 初始化顺序表函数
Status InitList_Sq(SqList &L)
{
    L.elem = new (nothrow) Book[MAXSIZE]; // 动态分配内存
    if (!L.elem)
        return ERROR; // 分配失败
    L.length = 0;     // 初始化长度为0
    return OK;
}

// 顺序表插入元素函数
Status ListInsert_Sq(SqList &L, int i, Book b)
{
    if (i < 1 || i > L.length + 1 || L.length == MAXSIZE)
        return ERROR; // 检查插入位置和空间
    for (int j = L.length - 1; j >= i - 1; --j)
    { // 将插入位置及之后的元素后移
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = b; // 插入元素
    L.length++;        // 更新顺序表长度
    return OK;
}

// 顺序表删除元素函数
Status ListDelete_Sq(SqList &L, int i)
{
    if (i < 1 || i > L.length)
        return ERROR; // 检查删除位置
    for (int j = i; j < L.length; ++j)
    { // 将删除位置之后的元素前移
        L.elem[j - 1] = L.elem[j];
    }
    L.length--; // 更新顺序表长度
    return OK;
}

// 顺序表显示函数
Status Printout_Sq(const SqList &L)
{
    if (L.length == 0)
    {
        cout << "顺序表为空" << endl;
        return ERROR;
    }

    // 设置表头格式
    cout << left;              // 左对齐
    cout << setw(10) << "位置" // 列宽为10
         << setw(10) << "编号"
         << setw(20) << "名称"
         << setw(10) << "定价" << endl;
    cout << "----------------------------------------------------" << endl;

    // 输出表格内容
    for (int i = 0; i < L.length; ++i)
    {
        cout << setw(10) << i + 1
             << setw(10) << L.elem[i].id
             << setw(20) << L.elem[i].name
             << setw(10) << fixed << setprecision(2) << L.elem[i].price << endl;
    }

    return OK;
}

// 顺序表查找函数
int ListSearch_Sq(const SqList &L, int id)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (L.elem[i].id == id)
        {
            return i; // 返回找到的元素位置
        }
    }
    return -1; // 未找到返回-1
}

// 主函数
int main()
{
    SqList L; // 定义顺序表
    if (InitList_Sq(L))
    {
        cout << "成功建立顺序表" << endl;
    }
    else
    {
        cout << "顺序表建立失败" << endl;
        return 1;
    }

    // 插入图书信息
    int Num;
    cout << "请选择要插入的图书数量: ";
    cin >> Num; // 获取图书数量
    for (int i = 0; i < Num; ++i)
    {
        int pos, id;
        string name;
        double price;

        cout << "请输入数据：插入的位置 图书编号 图书名称 图书价格（用空格隔开）:" << endl;
        cin >> pos >> id >> name >> price;

        Book b = {id, name, price}; // 构造图书对象
        if (ListInsert_Sq(L, pos, b))
        {
            cout << "插入成功！" << endl;
        }
        else
        {
            cout << "插入失败！" << endl;
        }
    }

    // 显示顺序表
    Printout_Sq(L);

    // 查找图书信息
    int searchId;
    cout << "请输入要查找的图书编号: ";
    cin >> searchId;
    int index = ListSearch_Sq(L, searchId);
    if (index != -1)
    {
        cout << "找到图书信息：" << endl;
        cout << "编号: " << L.elem[index].id << ", 名称: " << L.elem[index].name << ", 定价: " << fixed << setprecision(2) << L.elem[index].price << endl;
    }
    else
    {
        cout << "未找到该图书。" << endl;
    }

    // 删除图书信息
    int deletePos;
    cout << "请输入要删除的图书位置: ";
    cin >> deletePos;
    if (ListDelete_Sq(L, deletePos) == OK)
    {
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "删除失败！" << endl;
    }

    // 显示顺序表
    Printout_Sq(L);

    // 释放动态分配的内存
    delete[] L.elem;

    return 0;
}