#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

int solve(ll n, ll res) {
    if(n == 0) {
        return res;
    }
    return solve(n - 1, res + n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve(7, 0) << endl;

    return 0;
}