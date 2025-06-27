#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 2e6 + 5;

ll a[MOD], b[MOD];

void solve() {
    ll n, re;
    cin >> n;
    re = (n + 1) / 2;
    ll k = re;
    ll l = re;
    b[re] = n;
    for (int i = n - 1; i > 1; i--) {
        b[++l] = i;
        if (i != 1) {
            b[--k] = --i;
        }
    }
    if (n % 2 == 0) b[n] = 1;
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
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