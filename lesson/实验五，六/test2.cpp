#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

#define MAXSIZE 21

// 数据元素类型
typedef struct
{
    int Key;
    string Content;
} ElemType;

// 顺序表
typedef struct
{
    ElemType *r;
    int length;
} SSTable;

int InitList_SSTable(SSTable &L)
{
    L.r = new ElemType[MAXSIZE];
    if (L.r == nullptr)
    {
        cout << "内存分配失败！" << endl;
        return -1;
    }
    else
        cout << "内存分配成功！" << endl;
    L.length = 0;
    return 0;
}

int Insert_SSTable(SSTable &L)
{
    for (int i = 1; i < MAXSIZE; ++i)
    {
        L.r[i].Key = 100 + i;
        L.r[i].Content = "输出 " + to_string(i + 1);
        L.length++;
    }
    return 0;
}

void Show_Table(const SSTable &ST)
{
    for (int i = 0; i <= ST.length; ++i)
    {
        // cout << format("ST.[{}].key={}\t\tST.[{}].content={}\n", i, ST.r[i].Key, i, ST.r[i].Content);
    }
    cout << endl;
}

int Search_Seq(const SSTable &ST, int key)
{
    ST.r[0].Key = key; // 哨兵
    int i = ST.length;
    while (ST.r[i].Key != key)
    {
        --i;
    }
    cout << "查找过程: " << endl;
    for (int j = 1; j <= ST.length; ++j)
    {
        cout << "正在查找: ";
        if (j == i)
        {
            cout << "[" << ST.r[j].Key << "]\n";
            break;
        }
        else
        {
            cout << ST.r[j].Key << " \n";
        }
    }
    cout << endl;
    return i; // 返回找到的位置或 0
}

int Search_Bin(const SSTable &ST, int key)
{
    cout << "查找过程: " << endl;
    int low = 1, high = ST.length;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << "[" << low << "," << high << "] -> " << ST.r[mid].Key << endl;
        if (key == ST.r[mid].Key)
        {
            return mid;
        }
        else if (key < ST.r[mid].Key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0; // 未找到返回0
}

void Show_Result(int result, int key, const SSTable &ST)
{
    if (result > 0)
    {
        cout << "找到了键值为 " << key << " 的元素，位置是 " << result << ", 内容是: " << ST.r[result].Content << endl;
    }
    else
    {
        cout << "没有找到键值为 " << key << " 的元素。" << endl;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SSTable ST;
    if (InitList_SSTable(ST) != 0)
    {
        return -1; // 初始化失败退出
    }
    Insert_SSTable(ST);
    Show_Table(ST);

    // 顺序查找
    cout << "顺序查找：" << endl;
    Show_Result(Search_Seq(ST, 110), 110, ST);
    Show_Result(Search_Seq(ST, 200), 200, ST);

    // 折半查找
    cout << "折半查找：" << endl;
    Show_Result(Search_Bin(ST, 102), 102, ST);
    Show_Result(Search_Bin(ST, 118), 118, ST);
    Show_Result(Search_Bin(ST, 192), 192, ST);

    delete[] ST.r; // 释放内存

    return 0;
}