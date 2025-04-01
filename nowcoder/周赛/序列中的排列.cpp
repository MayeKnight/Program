#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e3 + 7;

ll a[MOD];

void solve() {
    ll n, k, p;
    cin >> n >> k;
    for(ll i = 1; i <= k; i++) {
        a[i] = 0;
    }
    for(ll i = 1; i <= n; i++) {
        cin >> p;
        a[p] = 1; 
    }
    for(ll i = 1; i <= k; i++) {
        if(a[i] != 1) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    for(ll i=1; i <= t; i++) {
        solve();
    }
    return 0;
}