class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), ans = 0, left = 0;
        unordered_map<int, int> res;  //解决在不定长滑动窗口中元素种类有限, 同时要求元素数量(最多)的问题
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            res[fruits[i]]++;
            while (res.size() > 2) {  //.size()指的是元素种类的数量(即当前窗口中不同水果的种类数量)
                res[fruits[left]]--;
                if (res[fruits[left]] == 0) {
                    res.erase(fruits[left]);  //删除键值对
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};