#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, mx = 0;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
            mx = max(mx, g[i][j]);
        }
    }

    //检查行操作  {}为作用域，外作用域的参数内作用域仍能调用，但当内作用域结束时, 内作用域中定义的会自动删除
    {
        vector<vector<int>> row(n);
        map<int, int> mp;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (g[i][j] == mx) {
                    row[i].push_back(j);
                    mp[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (row[i].empty()) {
                continue;
            }
            for (int j : row[i]) {  //遍历row[i]中所有列索引j
                if (--mp[j] == 0) {  //这个判断条件的意思是本列其他行均没有最大值了，在该列只有本行有最大值，此时可以将本列erase掉
                    mp.erase(j);
                }
            }
            if (mp.size() <= 1) {      //三种情况, mp.size()==0时，指移除某一行后, 所有mx都被覆盖, 选择该行和任意一列即可
                cout << mx - 1 << endl;  //mp.size() == 1时, 移除某一行后, 剩余的mx只集中于某一列(假设列j), 则选择该行和该列即可, 该行所有的mx都减一(覆盖部分mx), 列j所有的mx减一(覆盖剩余mx)
                return;                  //mp.size() > 1时, 剩余的mx分布在多列, 选择行r, 列c，只能覆盖行r所有的mx和列c所有的mx，其他列的mx不会被覆盖, 因此最大值仍为mx
            }
            for (int j : row[i]) {
                mp[j]++;
            }
        }
    }

    //检查列操作, 行处理只能检查"移除某一行"能否解决问题, 在某些情况下, 移除某一列可能更有效, 而行处理无法发现这种情况
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
                cout << mx - 1 << endl;
                return;
            }
            for (int i : col[j]) {
                mp[i]++;
            }
        }
    }

    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


