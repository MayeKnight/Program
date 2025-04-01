#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;
void solve(int n) {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += i;
    }
    cout << res << endl;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(6);
    return 0;
}