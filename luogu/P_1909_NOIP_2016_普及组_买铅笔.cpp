#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, a1, a2, b1, b2, c1, c2, m1, m2, m3, s1, s2, s3, ans;
    cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    if(n % a1 != 0) m1 = n / a1 + 1;
    else m1 = n / a1;
    if(n % b1 != 0) m2 = n / b1 + 1;
    else m2 = n / b1;
    if(n % c1 != 0) m3 = n / c1 + 1;
    else m3 = n / c1;
    s1 = m1 * a2;
    s2 = m2 * b2;
    s3 = m3 * c2;
    ans = min(min(s1,s2) , s3);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}
