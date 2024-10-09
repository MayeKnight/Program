#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

int ans(ll a, ll b, ll c) {
    ll s[3];
    s[0] = a; 
    s[1] = b;
    s[2] = c;
    sort(s, s+3);  //s+n，有几位元素，就 +n 位元素
    return s[0] + s[1] > s[2];
} 

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;  
    if (ans(a*2, b, c) || ans(a, b*2, c) || ans(a, b, c*2)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}