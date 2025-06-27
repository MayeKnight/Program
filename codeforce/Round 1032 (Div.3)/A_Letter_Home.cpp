#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        ll res = abs(a[0] - s);
        cout << res << endl;
        return;
    }
    else if (n > 1) {
        if (s <= a[0]) {
            cout << (a[n - 1] - s) << endl;
            return;
        }
        else if (s >= a[n - 1]) {
            cout << (s - a[0]) << endl;
        }
        else if (s > a[0] && s < a[n - 1]) {
            if ((s - a[0]) > (a[n - 1] - s)) {
                cout << (a[n - 1] - s + a[n - 1] - a[0]) << endl;
                return;
            }
            else cout << ((s - a[0]) + a[n - 1] - a[0]) << endl;
        }
    }
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