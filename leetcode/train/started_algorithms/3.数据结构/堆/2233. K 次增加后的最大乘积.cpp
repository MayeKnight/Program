class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    long long res = 0, ans = 1;
    vector<int> nums2;
public:
    int maximumProduct(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (k--) {
            res = pq.top() + 1;
            pq.pop();
            pq.push(res);
        }
        while (pq.size()) {
            nums2.push_back(pq.top());
            pq.pop();
        }
        //"分步取模"等价于"最后取模"
        for (int i = 0; i < nums2.size(); i++) {
            ans = (ans * nums2[i]) % (1'000'000'000 + 7);
        }
        return ans;
    }
};