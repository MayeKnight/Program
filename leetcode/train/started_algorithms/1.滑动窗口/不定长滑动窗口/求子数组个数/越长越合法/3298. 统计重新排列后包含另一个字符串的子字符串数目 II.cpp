class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        //注意解释, 均为小写英文字母...oops
        vector<int> res(26);
        long long ans = 0, left = 0;
        for (char c : word2) {
            res[c - 'a']++;
        }
        for (char c : word1) {
            //进入窗口
            res[c - 'a']--;
            //满足窗口条件
            while (detect(res)) {
                //收缩左边界
                res[word1[left] - 'a']++;
                left++;
            }
            ans += left;
        }
        return ans;
    }
    long long detect(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return 0;
            }
        }
        return 1;
    }
};