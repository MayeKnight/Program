#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;
void extend(ll *nums, ll size, ll enlarge) {    //这里ll *extend目的是返回一个数组, 而不是一个数, 所以为*extend()
    ll res[size + enlarge];
    for(ll i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    for(ll i = 0; i < size + enlarge; i++) {
        cout << res[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a[6] = {1, 2, 3, 4, 5, 6};
    ll enlarge = 3;
    extend(a, 6, enlarge);

    return 0;
}