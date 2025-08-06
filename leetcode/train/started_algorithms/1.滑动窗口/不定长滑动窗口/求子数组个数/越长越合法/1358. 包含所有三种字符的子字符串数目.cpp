class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), left = 0, ans = 0;
        vector<int> res(3);
        for (int right = 0; right < n; right++) {
            //进入窗口
            res[s[right] - 'a']++;  //a, b, c在ASCII码中连续, 以映射到0, 1, 2
            //满足窗口条件时
            while (res[0] && res[1] && res[2]) {
                res[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};