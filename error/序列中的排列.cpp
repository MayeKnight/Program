//error

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll t, n, k, a[100], cnt = 1;
    cin >> t;
    
    for(int i=1; i<=t; i++) {
        cin >> n >> k;
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }
        if(k > n) {
            cout << "NO" << endl;
        }
        else {
            for(int j = 0; j < n - 1; j++) {
                if(a[j] < k && (j + 1 + k) <= n) {
                        for(int j1 = j + 1; j1 < n; j1++) {
                            if(a[j] != a[j1]) cnt++;
                        }
                }
                
            }
            if(cnt != k) cout << "NO" << endl;
            else if(cnt == k) cout<< "YES" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}