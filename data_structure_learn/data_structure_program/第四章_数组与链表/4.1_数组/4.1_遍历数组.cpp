#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

ll solve(ll *nums, ll size) {
    ll count = 0;
    for(ll i = 0; i < size; i++) {
        count += nums[i];
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a[6] = {1, 2, 3, 4, 5, 6};
    cout << solve(a, 6) << endl;

    return 0;
}