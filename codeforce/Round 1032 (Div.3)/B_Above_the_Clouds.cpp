#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;
    set<ll> m;
    vector<char> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n - 1; i++) {
        if (a[i] == a[0] || a[i] == a[n - 1]) {
            cout << "Yes" << endl;
            return;
        }
        if (m.count(a[i])) {
            cout << "Yes" << endl;
            return;
        }
        m.insert(a[i]);
    }
    cout << "No" << endl;
    return;
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