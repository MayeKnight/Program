//递归是一种算法策略, 通过调用函数自身来解决问题, 主要包含两个阶段
//递: 程序不断深入地调用自身, 通常传入更小或更简化的参数, 直到达到"终止条件"(即基本情况, 且基本情况的解是已知的, 亦即人为设置的)
//归: 触发"终止条件"后, 程序从最深层的递归函数开始逐层返回, 汇聚每一层的结果
//在下述代码中, 我们只需调用函数solve(n), 就可以完成1加到n的计算

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;


int solve(ll n) {
    if(n == 1) {
        return 1;
    }
    ll res = solve(n-1);
    return n + res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve(7) << endl;

    return 0;
}