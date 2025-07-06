#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll s1 = accumulate(a.begin(), a.begin() + n / 2, 0ll);  //accumulate(起始迭代器, 结束迭代器, 初始值), 用于计算范围内元素的累加和 (区间为左闭右开), 0ll是0的long long类型字面量, 确保累加时使用64位整数运算, 避免溢出
    ll s2 = accumulate(a.begin() + n / 2, a.end(), 0ll);

    cout << s1 * s1 + s2 * s2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

//根据数学性质，固定总和的情况下，x² + y² 在 x 和 y 相差最大时取得最大值（即 x 尽可能大，y 尽可能小，或反之）
//最优策略：将木棒排序后，前半部分（较小的木棒）分配给一个方向，后半部分（较大的木棒）分配给另一个方向。