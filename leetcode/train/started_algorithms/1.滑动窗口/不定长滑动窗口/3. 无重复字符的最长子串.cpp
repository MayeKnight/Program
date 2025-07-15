class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxStr = 0, left = 0;
        unordered_set<char> res;  //用于记录当前窗口有哪些元素
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            while (res.find(s[i]) != res.end()) {  //在当前窗口中存在该元素
                res.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i - left + 1);
            res.insert(s[i]);
        }
        return maxStr;
    }
};