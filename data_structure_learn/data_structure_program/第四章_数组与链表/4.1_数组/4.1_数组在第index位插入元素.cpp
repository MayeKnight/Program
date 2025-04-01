#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve(ll *nums, ll num, ll size, ll index) {
    for(ll i = size - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a[6] = {1, 2, 3, 4, 5, 6};
    solve(a, 0, 6, 2);
    for(int i = 0; i < 6; i++) {
        cout << a[i] << endl;
    }

    return 0;
}