#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> bmin(n);
    vector<ll> bmax(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    bmin[0] = a[0];
    bmax[n - 1] = a[n - 1];

    for (ll i = 1; i < n; i++) {
        bmin[i] = min(bmin[i - 1], a[i]);
    }

    for (ll j = n - 2; j > 0; j--) {
        bmax[j] = max(bmax[j + 1], a[j]);
    }

    vector<ll> res(n);
    res[0] = 1;
    res[n - 1] = 1;
    for (ll i = 0; i < n; i++) {
        if (a[i] == bmin[i] || a[i] == bmax[i]) {  //保证题目要求的允许交替选择前缀和后缀操作
            res[i] = 1;
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << res[i];
    }

    cout << endl;
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
