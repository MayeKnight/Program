#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

// 定义哈夫曼树节点
struct HTNode {
    int weight; // 节点的权值
    int parent; // 节点的双亲下标
    int lchild; // 节点的左孩子下标
    int rchild; // 节点的右孩子下标
};
using HuffmanTree = vector<HTNode>;

// 选择权值最小的两个节点
void Select(HuffmanTree& HT, int n, int& s1, int& s2) {
    int min1 = INT_MAX, min2 = INT_MAX;
    s1 = s2 = -1;
    for (int i = 1; i <= n; ++i) {
        if (HT[i].parent == 0 && HT[i].weight < min1) {
            min2 = min1;
            s2 = s1;
            min1 = HT[i].weight;
            s1 = i;
        } else if (HT[i].parent == 0 && HT[i].weight < min2) {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
}

// 创建哈夫曼树
void CreateHuffmanTree(HuffmanTree& HT, const vector<int>& weights) {
    int n = weights.size();
    HT.resize(2 * n);
    for (int i = 1; i <= 2 * n - 1; ++i) {
        HT[i] = {0, 0, 0, 0};
    }
    for (int i = 1; i <= n; ++i) {
        HT[i].weight = weights[i - 1];
    }
    for (int i = n + 1; i <= 2 * n - 1; ++i) {
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// 显示哈夫曼树节点状态
void Printout(const HuffmanTree& HT) {
    cout << "节点编号\t权重\t双亲\t左孩子\t右孩子\n";
    for (int i = 1; i < HT.size(); ++i) {
        cout << "\t" << i << "\t\t" << HT[i].weight << "\t\t" << HT[i].parent << "\t\t" << HT[i].lchild << "\t\t" << HT[i].rchild << "\n";
    }
}

// 定义哈夫曼编码表
struct HuffmanCode {
    int start; // 编码起始位置
    string code; // 编码字符串
};
using HuffmanCodes = vector<HuffmanCode>;

// 创建哈夫曼编码
void CreateHuffmanCode(const HuffmanTree& HT, HuffmanCodes& HC) {
    int n = HT.size() / 2; // 叶子节点数
    HC.resize(n);
    for (int i = 1; i <= n; ++i) {
        int c = i, f = HT[i].parent;
        HC[i - 1].start = 0;
        HC[i - 1].code = "";
        while (f != 0) {
            if (HT[f].lchild == c) {
                HC[i - 1].code = "0" + HC[i - 1].code;
            } else {
                HC[i - 1].code = "1" + HC[i - 1].code;
            }
            c = f;
            f = HT[f].parent;
        }
    }
}

// 显示哈夫曼编码表
void PrintHuffmanCode(const HuffmanCodes& HC, const vector<int>& weights) {
    cout << "相应字符\t权重\t哈夫曼编码\n";
    for (int i = 0; i < HC.size(); ++i) {
        cout << "\t" << char('A' + i) << "\t\t" << weights[i] << "\t\t" << HC[i].code << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    vector<int> weights = {5, 29, 7, 8, 14, 23, 3, 11};
    HuffmanTree HT;
    CreateHuffmanTree(HT, weights);
    Printout(HT);

    cout << endl;

    HuffmanCodes HC;
    CreateHuffmanCode(HT, HC);
    PrintHuffmanCode(HC, weights);

    return 0;
}