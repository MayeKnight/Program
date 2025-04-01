#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

int RandomAccess(ll *nums, ll size) {
    ll random = rand() % size;  //rand()为一随机数, 对size取余后即可得到[0, size)的随机数
    ll ans = nums[random];  //获取数组中的随机元素
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a[10] = {2, 3, 4, 5, 6, 7, 7, 8, 5, 3};
    cout << RandomAccess(a, 8) << endl;

    return 0;
}