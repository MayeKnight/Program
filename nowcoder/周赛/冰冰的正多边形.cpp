#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll t, n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        ll a[n];
        for(int j = 0; j < n; j++) {
            cin >> a[j]; 
        }
        //相同数,思路：多排，提，比较大小
        ll c = 0, ans = MOD;
        for(int j = 0; j < n; j++) {
            for(int k = j; k < n; k++) {
                if(a[j] == a[k]) {
                    c++;
                }
            }
            if(c >= 3 && ans > (3 * a[j])) {
                ans = 3 * a[j];
                c = 0;
            }
            else c = 0;
        }
        if(ans == MOD) {
            cout << "no" << endl;
        }
        else {
            cout << "yes" << endl;
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}