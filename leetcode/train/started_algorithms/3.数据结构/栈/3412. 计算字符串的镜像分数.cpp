class Solution {
public:
    long long calculateScore(string s) {
        stack<int> stk[26];
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!stk[26 - (s[i] - 'a' + 1)].empty()) {
                ans += (i - stk[26 - (s[i] - 'a' + 1)].top());
                stk[26 - (s[i] - 'a' + 1)].pop();
            }
            else {
                stk[s[i] - 'a'].push(i);
            }
        }
        return ans;
    }
};

0 1 2 3 4 5
//0  6-(0+1) = 5
//1  6-(1+1) = 4
//2  6-(2+1) = 3
//3  6-(3+1) = 2


