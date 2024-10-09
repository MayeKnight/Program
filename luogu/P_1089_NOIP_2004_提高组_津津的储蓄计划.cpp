#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll m, n = 0, sum = 0, c, i;
    for(i = 0; i < 12; i++){
        n += 300;
        cin >> c;
        n -= c;
        if(n < 0){
            cout << -i-1;
            break;
        }
        else if(n >= 100){
            sum += n / 100 * 100;
            n %= 100;
        }
    }
    if(i == 12){
        cout << n + sum * 1.2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}