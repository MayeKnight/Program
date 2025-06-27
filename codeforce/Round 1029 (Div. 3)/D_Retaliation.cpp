#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 2e7 + 5;
ll a[MOD];

void solve() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto check = [&]() -> bool {    //这里定义了个lambda函数check，[&]表示该lambda函数按引用捕获外部变量, 如a, 可以直接访问他们, -> bool 显式声明该lambda返回bool类型
        if (a[0] < 0) return false;  //若a[0] < 0 返回false, 
        if (a[0] % (n + 1)) return false;  //若a[0]不能模0 返回false
        for (ll i = 0; i < n; i++) {
            if (a[i] != a[0]) return false;   //若a[i] != a[0] 返回false
        }
        return true;
        };
    bool res = true;
    if (a[0] == a[1]) {
        res = check();
    }
    else if (a[0] < a[1]) {
        ll cut = a[1] - a[0];
        for (ll i = 0; i < n; i++) a[i] -= cut * (i + 1);
        res = check();
    }
    else {
        ll cut = a[n - 2] - a[n - 1];
        for (ll i = 0; i < n; i++) a[i] -= cut * (n - i);
        res = check();
    }
    cout << (res ? "YES" : "NO") << endl; //res为true是输出yes, 否则输出no
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

