//枚举, 1,3,6,10,15求n的最小硬币数量
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll ans = 1e9 + 5; //1e9为10的9次方，2e9为2*10的9次方
    ll n;
    cin >> n;
    for (int i = 0; i <= 2; i++)   //你可能会想先全用15再拼一拼别的，这样效率太低了
    {                                    //很经典的一道，观察一下，是有倍数关系的，1块钱的最多只有2个，不能有3个，因为如果有3个，那为什么不换成1个三块钱呢？其他同理
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 4; k++)
            {
                for (int l = 0; l <= 2; l++)
                {
                    ll need = n - i - 3 * j - 6 * k - 10 * l;
                    if (need % 15 != 0 || need < 0) continue;
                    ans = min(ans, i + j + k + l + need / 15);  //1
                }
            }
        }
    }
    cout << ans << endl;  //这一步在for循环外是为了遍历完上述'1'那一行后得出最小的ans
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