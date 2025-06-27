//树, dfs, 快速幂模板

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

//快速幂模板如下
constexpr int M = 1e9 + 7;

ll powp(ll a, ll n) {  //快速幂powp(ll a, ll n), 功能是 'a的n次方 mod M'.  即计算a的n次方，并取模M, 其中 M = 1e9 + 7.
    a %= M;
    ll ans = 1;
    while (n) {
        if (n & 1) (ans *= a) %= M;  //n&1, 是一种高效的位运算方法, 用于判断整数n是否为奇数.
        (a *= a) %= M;
        n >>= 1;  //是右移运算, (他在计算机中的效果等价于整数除以2并向下取整) 即等效于n/2, 但速度更快, 因为它是直接对二进制位进行操作.
    }
    return ans;
}

ll inv(ll x) {  //模逆元inv(ll x), 功能是 'x的-1次方 mod M'.  即计算x的-1次方在模M下成乘法逆元
    return powp(x, M - 2);
}

//

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> edg(n, vector<int>());  //这里意为声明一个含有n个元素, 且元素类型为vector<int>并初始化为空的二维数组edg
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    if (n == 2) {
        cout << 4 << endl;
        return;  //return; 在这里的作用是结束当前函数solve()的执行，并返回到main()函数中。由于solve()函数的返回类型是void, 所以直接使用return, 而不带任何返回值
    }

    vector<int> leave;  //用于存储树的末端节点(没有子节点的节点)位置, 亦即叶子结点位置. 
    for (int i = 1; i < n; i++) {
        if (edg[i].size() == 1) {  //这里判断条件是edg[i]为叶子结点(其连接别的结点的数量为1)
            leave.push_back(i);
        }
    }

    if (leave.size() > 2) {  //且依据题意, 当叶子结点大于2时, 赋值1, 2不够分, 必然无解.
        cout << 0 << endl;
        return;
    }

    if (leave.size() == 1) {
        cout << powp(2, n) << endl; // 这里是指叶子结点为n时, 情况有2的n次方种
        return;
    }

    // cout << "pass" << endl; //这里是用于将尚未考虑的情况先pass掉, 验证我们已经写好的是否有问题.

    //深度优先遍历dfs得出各个结点对应树的深度dep(n), 其中dep[0], dep[1], dep[2]...分别表示节点0, 1, 2, 的深度
    vector<int> dep(n);
    auto dfs = [&](auto&& self, int now, int from) ->void {  //dfs lambda函数, 其中[&]通过引用捕获外部变量, 如edg, 避免拷贝, auto&& self允许lambda捕获自身, 并按值或引用传递, 从而支持递归调用(lambda函数在C++中默认不能直接调用自己), -> void 显示指定返回类型为void
        for (auto nxt : edg[now]) {  //遍历now所有的邻居nxt. now为当前访问的结点, from为当前结点的父结点, 防止回溯
            if (nxt == from) continue; // 如果nxt为父节点from, 则跳过(防止无限递归)
            dep[nxt] = dep[now] + 1; //子节点深度 = 当前节点深度 + 1
            self(self, nxt, now); // 继续递归处理子节点 nxt, 并记录父结点为now
        }
        };
    dep[0] = 1; //确定结点0深度为1
    dfs(dfs, 0, -1);  //调用dfs, 从根结点0开始, 父结点为-1(表示无父节点)


    int lc = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (edg[i].size() >= 3) {
            lc = i; //确定树在哪个结点分支.
            break;
        }
    }

    int u = leave[0], v = leave[1]; //由题意得, 树从根节点到叶节点分两支, 即最多只有两个叶节点
    int z = dep[lc] + abs(dep[u] - dep[v]);
    cout << (powp(2, z) + powp(2, z - (dep[u] != dep[v]))) % M << endl; //其中dep[u] != dep[v] 意思为若不等, 返回1. 若相等, 返回0

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}