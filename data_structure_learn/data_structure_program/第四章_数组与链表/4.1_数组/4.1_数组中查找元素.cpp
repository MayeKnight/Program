#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

ll solve(ll *nums, ll size, ll target) {
    for(ll i = 0; i < size; i++) {
        if(nums[i] == target) {
            return i;  //通常情况下, 在C++中, 一个函数只有一个返回值, 所以若返回i，i即为所需的数组索引, 则本子函数终止, 即遍历也同样终止, 若遍历完仍没有达成nums[i] == target, 则返回-1, 意为未找到target
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a[6] = {1, 2, 3, 4, 5, 6};
    cout << solve(a, 6, 3) << endl;

    return 0;
}