class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> res(26);
        int n = s.size(), ans = 0, left = 0;
        for (char c : s) {
            //进入窗口
            res[c - 'a']++;
            //窗口满足条件
            while (ranges::max(res) == k) {
                //收缩左边界
                res[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};