

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

#define MAXSIZE 20

// 数据元素类型
typedef struct {
    int Key;
    string Content;
} ElemType;

// 顺序表
typedef struct {
    ElemType* r;
    int length;
} SqList;

void Create_Sq(SqList& L, int n) {
    if (n > MAXSIZE || n <= 0) {
        cout << "输入的数据量超出范围！" << endl;
        return;
    }
    L.r = new ElemType[MAXSIZE + 1];
    L.length = 0;
    for (int i = 0; i < n; ++i) {
        cin >> L.r[i].Key;
        cout << "请输入第 " << i + 1 << " 个元素的输入值: " << L.r[i].Key << endl;
        L.r[i].Content = "输出 " + to_string(i + 1);
        L.length++;
    }
    cout << endl;
}

void show(const SqList& L) {
    for (int i = 0; i < L.length; ++i) {
        cout << "输入: " << L.r[i].Key << ", 输出: " << L.r[i].Content << endl;
    }
    cout << endl;
}

// 插入排序
void InsertSort(const SqList& L) {
    for (int i = 1; i < L.length; ++i) {
        ElemType temp = L.r[i];
        int j = i - 1;
        while (j >= 0 && L.r[j].Key > temp.Key) {
            L.r[j + 1] = L.r[j];
            --j;
        }
        L.r[j + 1] = temp;
    }
}

// 折半插入排序
void BInsertSort(const SqList& L) {
    for (int i = 1; i < L.length; ++i) {
        ElemType temp = L.r[i];
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (L.r[mid].Key > temp.Key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; --j) {
            L.r[j + 1] = L.r[j];
        }
        L.r[high + 1] = temp;
    }
}

// 冒泡排序
void BubbleSort(const SqList& L) {
    for (int i = 0; i < L.length - 1; ++i) {
        for (int j = L.length - 1; j > i; --j) {
            if (L.r[j - 1].Key > L.r[j].Key) {
                swap(L.r[j - 1], L.r[j]);
            }
        }
    }
}

// 快速排序
void QuickSort(const SqList& L, int low, int high) {
    if (low < high) {
        int pivot = L.r[low].Key;
        int i = low, j = high;
        while (i < j) {
            while (i < j && L.r[j].Key >= pivot) {
                --j;
            }
            if (i < j) {
                L.r[i++] = L.r[j];
            }
            while (i < j && L.r[i].Key <= pivot) {
                ++i;
            }
            if (i < j) {
                L.r[j--] = L.r[i];
            }
        }
        L.r[i].Key = pivot;
        QuickSort(L, low, i - 1);
        QuickSort(L, i + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);




    SqList L;
    L.r = nullptr;
    L.length = 0;

    int n;
    cout << "请输入要创建的顺序表的元素个数 (最大不超过20): " << endl;
    cin >> n;
    Create_Sq(L, n);

    cout << "当前表的结果为：" << endl;
    show(L);

    // 调用各种排序方法
    InsertSort(L);
    cout << "直接插入排序后的结果为：" << endl;
    show(L);

    BInsertSort(L);
    cout << "折半插入排序后的结果为：" << endl;
    show(L);

    BubbleSort(L);
    cout << "冒泡排序后的结果为：" << endl;
    show(L);

    QuickSort(L, 0, L.length - 1);
    cout << "快速排序后的结果为：" << endl;
    show(L);

    delete[] L.r;

    return 0;
}