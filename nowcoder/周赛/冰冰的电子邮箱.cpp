#include <bits/stdc++.h>
#include <string>
#include <regex>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string s;
        cin >> s;
        string s1 = s.substr(0, s.find('@'));
        string s2 = s.substr(s.find('@') + 1);
    

        bool ans1 = s1.front() != '.';
        bool ans2 = s1.back() != '.';
        bool ans3 = s2.front() != '-';
        bool ans4 = s2.back() != '-';
        bool ans5 = s2.front() != '.';
        bool ans6 = s2.back() != '.';

        if(regex_match(s, regex(R"(^[a-zA-Z0-0.]+@[a-zA-Z0-9.-]+$)")) && ans1 && ans2 && ans3 && ans4 && ans5 && ans6) {
            cout << "Yes" << endl;
        }

        else cout << "No" << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}