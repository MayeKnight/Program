/* 
从cin输入一组数，求其和
本例中循环条件是cin>>value，此表达式读取一个数存在value中，输入运算符返回其左侧运算对象cin，是一个istream对象
其效果是检测流的状态，如果流是有效的，即流未遇到错误，则检测成功，若遇到文件运算符（ctrl+z）或一个无效的输入时，
istream对象状态就会变为无效，会使判断条件变为假。 
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll sum = 0, value = 0;
    
    while(cin >> value) {    //可以看出循环的判定条件是“cin>>value”，但输入完数据后要加上，文件结束符，按Ctrl+Z，再enter输出。
        sum += value;
    }
    cout << sum << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

