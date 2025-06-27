#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 2e6 + 5;

ll a[MOD];

int solve() {
    ll n, x, re = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            re = i;
            break;
        }
    }
    re = re + (x - 1);
    if (re >= n) {
        cout << "YES" << endl;
        return 0;
    }
    else {
        for (int i = re + 1; i <= n; i++) {
            if (a[i] == 1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        return 0;
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