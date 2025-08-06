class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        unordered_map<int, int> res;
        int ans = 0, left = 0;
        for (int i = 0; i < flowers.size(); i++) {
            //进入窗口
            res[flowers[i]]++;
            //满足窗口条件
            while (res[flowers[i]] > cnt) {
                //收缩左边界
                res[flowers[left]]--;
                left++;
            }
            ans += i - left + 1;
        }
        return ans % 1'000'000'007;  //1e9为double类型, 不能与int类型的int进行取模运算
    }
};