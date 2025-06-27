#include<stdio.h>

#define MOD (100000000 + 5)

typedef long long ll;

void solve()
{
    ll n, m, a, b, c, d;
    scanf("%lld %lld", &n, &m);
    printf("? 1 1\n");
    fflush(stdout);
    scanf("%lld", &a);
    printf("? %lld 1\n", n);
    fflush(stdout);
    scanf("%lld", &b);
    printf("? %lld %lld\n", n, m);
    fflush(stdout);
    scanf("%lld", &c);
    ll x1 = (a - b + 1 + n) / 2;
    ll y1 = (a + b + 3 - n) / 2;
    ll x2 = (m + 2 * n - c - b - 1) / 2;
    ll y2 = (m + b + 1 - c) / 2;
    if (x1 <= 0 || y1 <= 0 || x1 > n || y1 > m) {
        printf("! %lld %lld\n", x2, y2);
        fflush(stdout);
    }
       
    else {
        printf("? %lld %lld\n", x1, y1);
        fflush(stdout);
        scanf("%lld", &d);
        if (d == 0) {
            printf("! %lld %lld\n", x1, y1);
            fflush(stdout);
        }
        else {
            printf("! %lld %lld\n", x2, y2);
            fflush(stdout);
        }
    }
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