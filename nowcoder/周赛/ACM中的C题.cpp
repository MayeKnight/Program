#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    if(n!=1 && n%2 == 1) cout << n/2+1;
    else if(n!=1 && n%2 == 0) cout << n/2;
    else cout<< -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}