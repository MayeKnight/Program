#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, c, ans = 0, p = 0;
    cin >> n >> c;
    if(n > 0) {
        ans++;
    }
    ll t[n];
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    p = t[0];
    for(int i = 1; i < n; i++) {
        if(t[i] >= p + c) {
            p = t[i];
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}