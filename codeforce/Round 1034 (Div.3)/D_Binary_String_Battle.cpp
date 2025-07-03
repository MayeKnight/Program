#include<bits/stdc++.h>

using namespace std;
using ll = long long;  //这里是 using ll = long long;

void solve()
{
    ll n, k, res = 0;
    string s;  //题设为字符串(中间没有空格, 故不能用数组存储)

    cin >> n >> k;
    cin >> s;

    for (ll i = 0; i < s.size(); i++) {  //s.size()为字符串大小用于for循环的限制条件
        if (s[i] == '1') {  //声明的s为string类型, 但是string的operator[]操作(用于访问字符串的中单个字符的成员函数) s[i] 返回的是char类型, 而不是int类型, 所以这里为 '1' 
            res++;
        }
    }
    if (res <= k) cout << "Alice" << endl;
    else if (n < 2 * k) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}