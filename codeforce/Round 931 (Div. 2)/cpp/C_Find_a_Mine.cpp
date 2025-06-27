//interactive problem 交互题
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {  //x代表行，y代表列，与n,m一一对应
    ll n, m, a, b, c;
    cin >> n >> m;
    cout << "? 1 1" << endl;  //endl是输出控制符，不能在cin中使用
    fflush(stdout);
    cin >> a;
    cout << "? " << n << " " << 1 << endl;
    fflush(stdout);
    cin >> b;
    cout << "? " << n << " " << m << endl;
    fflush(stdout);
    cin >> c;
    ll x1 = (a - b + 1 + n) / 2;  //x1, y1, x2, y2的确定是通过画图，列二元一次方程组得到的
    ll y1 = (a + b + 3 - n) / 2;
    ll x2 = (m + 2 * n - c - b - 1) / 2;
    ll y2 = (b - c + m + 1) / 2;
    if (x1 <= 0 || y1 <= 0 || x1 > n || y1 > m) {
        cout << "! " << x2 << " " << y2 << endl;
        fflush(stdout);
    }
    else {
        cout << "? " << x1 << " " << y1 << endl;
        fflush(stdout);
        ll d;
        cin >> d;
        if (d == 0) {
            cout << "! " << x1 << " " << y1 << endl;
            fflush(stdout);
        }
        else {
            cout << "! " << x2 << " " << y2 << endl;
            fflush(stdout);
        }
    }
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