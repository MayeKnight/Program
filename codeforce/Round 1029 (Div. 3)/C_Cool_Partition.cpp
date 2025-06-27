//贪心
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n); //注意这里为(), 定义一个名为 a 的 动态数组（vector），包含 n 个元素，每个元素是 int 类型，初始值为 0。
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> s, t;
    s.insert(a[0]); //这里是先将a[0]插入s，作为第一段
    int res = 1; //res为段的个数，这里先设为1
    for (int i = 1; i < n; i++) {
        s.erase(a[i]); //从集合s中删除a[i] (如果存在的话)
        t.insert(a[i]); //t作为下一段并插入a[i]
        if (s.empty()) { //若集合s删完了，则说明下一段t中已经包含s中所有元素，段数res++, 将t段赋给s, t清空，用于存下下一段
            res++;
            s = t;
            t.clear();
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m;
    cin >> m;
    while (m--) {
        solve();
    }

    return 0;
}



// pro_cptition_skills中
// 4.set<int> s; //round 1029 C 贪心
// set"集合"是C++标准模板库(STL)中的一个容器, 它的特点是:
// (1)不允许重复元素
// (2)自动排序(默认按升序排列)
// (3)常见底层实现是红黑树(balanced binary search tree)
// 常见操作如下 :
//     s.insert(x) 插入元素x
//     s.erase(x) 删除元素x(如果存在)
//     s.empty(x) 集合s判空, 若为空则返回1, 否则返回0
//     s.count(x) 返回0或1, 判断是否包含x
//     s.find(x) 返回指向x的迭代器, 找不到返回s.end()
//     s.clear(x) 清空所有元素
//     s.size() 返回元素个数