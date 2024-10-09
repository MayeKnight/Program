#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll a, b, m = 0, ans = 0;
    for(int i = 1; i <= 7; i++) {
        cin >> a >> b;
        if((a + b) > 8) {
            if((a + b) > m) {
                m = a + b;
                ans = i;
            }
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