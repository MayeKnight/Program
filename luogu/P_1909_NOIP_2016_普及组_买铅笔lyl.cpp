#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9+7;

/*
    6 / 3 = 2
    (6 + 2) / 3

    7 / 3 = 3
    (7+2) / 3

    a / b 上 == (a + b-1) / b  上取整
*/

void solve() {
    int n;
    cin >> n;

    ll mn = LLONG_MAX; // numeric_limits<ll>::max()  取ll最大值
    for(int i = 0; i < 3; ++i) {
        ll a, b;
        cin >> a >> b;

        mn = min(mn, (n + (a - 1)) / a * b);
    }
    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}