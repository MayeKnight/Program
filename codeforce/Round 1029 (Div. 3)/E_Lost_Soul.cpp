#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 2e6 + 5;

ll a[MOD], b[MOD];  //数组建议设为全局数组

void solve() {
    ll res = -1;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (ll i = 0; i < (n - 1); i++) {
        if (a[i] == a[i + 1] || b[i] == b[i + 1]) res = max(res, i);
    }
    for (ll i = 0; i < n; i++) {
        if (a[i] == b[i]) res = max(res, i);
    }
    set<ll> s;
    for (ll i = (n - 1); i >= 1; i--) {  //隔了一位位序操作
        if (s.count(a[i - 1]) || s.count(b[i - 1]))  //对于名为s的集合set, s.count(a)是验明集合s中是否存在a, 若存在则返回1, 反之则返回0
            res = max(res, (i - 1));
        s.insert(a[i]);
        s.insert(b[i]);
    }
    cout << (res + 1) << endl;
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