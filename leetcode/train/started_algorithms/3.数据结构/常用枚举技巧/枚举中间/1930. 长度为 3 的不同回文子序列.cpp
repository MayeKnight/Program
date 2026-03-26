class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char alpha = 'a'; alpha <= 'z'; alpha++) {
            int i = s.find(alpha);
            if (i == string::npos) {
                continue;
            }
            bool has[26]{};
            int j = s.rfind(alpha);
            for (int k = i + 1; k < j; k++) {  //循环体内i不能重复定义awa
                if (has[s[k] - 'a']) {
                    continue;
                }
                has[s[k] - 'a'] = true;
                ans++;
            }
        }
        return ans;
    }
};