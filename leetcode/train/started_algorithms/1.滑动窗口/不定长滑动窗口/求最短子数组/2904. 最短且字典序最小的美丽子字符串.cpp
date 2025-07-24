class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), left = 0, sum = 0;
        string res, ans = s + '1';
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                sum++;
            }
            while (sum == k) {
                res = s.substr(left, i - left + 1);  //s.substr(pos, len)指从字符串s的索引pos处开始提取长度为len的字符串
                if (i - left + 1 < ans.length()) {
                    ans = res;
                }
                else if (i - left + 1 == ans.length()) {
                    ans = compare(res, ans);
                }
                if (s[left] == '1') {
                    sum--;
                }
                left++;
            }
        }
        if (ans == s + '1') {
            return "";
        }
        return ans;
    }

    string compare(string s1, string s2) {
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] == '0' && s2[i] == '1') {
                return s1;
            }
            else if (s1[i] == '1' && s2[i] == '0') {
                return s2;
            }
        }
        return s1;
    }
};