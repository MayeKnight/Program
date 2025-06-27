// Date: 2025-06-17  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            mx = max(mx, g[i][j]);
        }
    }

    //检查行操作  {}作用域，作用域有包含关系，若是在内作用域内定义的，则该内作用域可以调用其被包含的外作用域的值，同时，内作用域结束，则内作用域定义的自动删除
    {
        vector<vector<int>> row(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == mx) {
                    row[i].push_back(j); //确定最大值行列位置
                    mp[j]++;  //并记录每列中包含最大值的次数
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (row[i].empty()) {
                continue;    //跳过没有最大值的行
            }
            for (int j : row[i]) {  //开始处理有最大值的行，对该行所有值遍历
                if (--mp[j] == 0) {  //若某列中在该行所包含最大值次数为0，从mp中移除该列
                    mp.erase(j);
                }
            }
            if (mp.size() <= 1) {  //题意指如果还剩一列可以-1
                cout << mx - 1 << "\n";
                return;
            }
            for (int j : row[i]) {
                mp[j]++;//将处理完上述操作的无关项，mp加回来
            }
        }
    }

    //检查列操作
    {
        vector<vector<int>> col(m);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == mx) {
                    col[j].push_back(i);
                    mp[i]++;
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (col[j].empty()) {
                continue;
            }
            for (int i : col[j]) {
                if (--mp[i] == 0) {
                    mp.erase(i);
                }
            }
            if (mp.size() <= 1) {
                cout << mx - 1 << "\n";  //题意指如果还剩一行可以-1
                return;
            }
            for (int i : col[j]) {
                mp[i]++;  //要看下一列，所以删的东西要回复过来
            }
        }
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}