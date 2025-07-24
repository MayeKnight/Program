class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), res = 0, ans = 0, left = 0;
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            res += abs(s[i] - t[i]);
            while (res > maxCost) {
                res -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};