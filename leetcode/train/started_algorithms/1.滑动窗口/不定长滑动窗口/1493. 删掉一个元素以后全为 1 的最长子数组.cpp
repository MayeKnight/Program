class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //维护一个滑动窗口, 其中最多只有一个0即可
        int n = nums.size(), max1 = 0, left = 0;
        multiset<int> res;  //记录当前窗口有哪些元素
        if (n == 1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            while (res.count(0) > 1) {
                res.erase(res.find(nums[left]));   // .find()返回指向res中第一个s[i]的迭代器以删去第一个s[i]
                left++;
            }
            if (nums[i] == 0) {
                max1 = max(max1, i - left - 1);
            }
            else {
                max1 = max(max1, i - left);
            }
            res.insert(nums[i]);
        }
        return max1;
    }
};