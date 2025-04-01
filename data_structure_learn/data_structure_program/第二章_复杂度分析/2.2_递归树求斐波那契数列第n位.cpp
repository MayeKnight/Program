#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

int solve(ll n) {
    if(n == 1 || n == 2) {
        return n - 1;
    }
    ll res = solve(n - 1) + solve(n - 2);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve(6) << endl;

    return 0;
}