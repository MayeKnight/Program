#include<stdio.h>
#include<stdlib.h> //需要用到stdlib.h头文件中的qsort函数对数组进行排序

#define MOD (2000000 + 5)  //C++ static constexpr int MOD = 2e6 + 5

typedef long long ll; //C++ using ll = long long;

ll a[MOD];

void solve() {
    ll n;
    scanf("%lld", &n); //C++ cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    //使用C标准库qsort函数时，必须提供一个compare比较函数，用于告诉qsort如何比较两个元素，从而决定他们的排序顺序
    int compare(const void* x, const void* y) {
        ll arg1 = *(const ll*)x;
        ll arg2 = *(const ll*)y;
        if (arg1 < arg2) return -1; //x应拍y前面
        if (arg1 > arg2) return 1; //x应排y后面
    }

    //a+1表示从第1位元素（不是第0位）开始排序, n表示告诉qsort有n个元素需要排序
    qsort(a + 1, n, sizeof(ll), compare);

    ll ans = 0;
    ans = a[n] - a[1] + a[n - 1] - a[1] + a[n - 1] - a[2] + a[n] - a[2];
    printf("%lld\n", ans);
}

int main() {
    ll t;
    scanf("%lld", &t); //C++ cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


