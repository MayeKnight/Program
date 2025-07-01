#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, j, k, res;
    cin >> n >> j >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k >= 2) {
        cout << "YES" << endl;
    }

    else if (k == 1) {
        res = a[j - 1];
        sort(a.begin(), a.end()); //sort函数需要两个参数, 其实迭代器.begin()和结束迭代器.end()表示要排序的范围
        if (res >= a[n - 1]) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
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