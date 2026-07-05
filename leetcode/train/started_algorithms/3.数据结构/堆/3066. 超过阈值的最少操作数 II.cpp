class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<long long> v(nums.begin(), nums.end());
        long long res1 = 0, res2 = 0, res3 = 0, ans = 0;
        make_heap(v.begin(), v.end(), greater<long long >());
        while (v[0] < k && v.size() >= 2) {    //在循环外侧判断nums.size() >= 2, 而不在循环内指明 nums.size() >= 2 可能导致因不能确定循环内 nums[1] 的存在而堆溢出.故这里将 nums.size() >= 2 写到循环判断条件中去了 
            res1 = v[0];                          //但索引1(nums[1])不一定是堆中第二大或第二小的元素, 而要使用 pop_heap后, 取新的nums[0]     
            pop_heap(v.begin(), v.end(), greater<long long>());
            v.pop_back();
            res2 = v[0];
            pop_heap(v.begin(), v.end(), greater<long long>());
            v.pop_back();
            res3 = min(res1, res2) * 2 + max(res1, res2);
            v.push_back(res3);
            push_heap(v.begin(), v.end(), greater<long long>());
            ans++;
        }
        return ans;
    }
};