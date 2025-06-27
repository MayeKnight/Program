#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 2e6 + 5;

ll a[MOD];

void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    ans = a[n] - a[1] + a[n - 1] - a[1] + a[n - 1] - a[2] + a[n] - a[2];
    cout << ans << endl;
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