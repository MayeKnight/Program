#include<stdio.h>

#define MOD (1000000000+5)

typedef long long ll;

//C需要自行定义min函数
ll min(ll a, ll b)
{
    if (a < b) return a;
    else return b;
}

void solve()
{
    ll n;
    scanf("%lld", &n);
    ll ans = MOD;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 4; k++) {
                for (int l = 0; l <= 2; l++) {
                    ll need = n - i - 3 * j - 6 * k - 10 * l;
                    if (need % 15 != 0 || need < 0) continue;
                    ans = min(ans, i + j + k + l + need / 15);
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    ll t;
    scanf("%lld", &t);
    while (t--) {
        solve();
    }

    return 0;
}