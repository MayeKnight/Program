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
                if (--mp[j] == 0) {
                    mp.erase(j);
                }
            }
            if (mp.size() <= 1) {
                cout << mx - 1 << endl;
                return;
            }
            for (int j : row[i]) {
                mp[j]++;
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


