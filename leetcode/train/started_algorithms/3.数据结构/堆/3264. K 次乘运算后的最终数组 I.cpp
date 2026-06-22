class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (k--) {
            res = pq.top();
            auto it = find(nums.begin(), nums.end(), res);
            pq.pop();
            res *= multiplier;
            pq.push(res);
            nums[it - nums.begin()] = res;
        }
        // while (pq.size()) {
        //     ans.push_back(pq.top());  
        //     pq.pop();
        // }
        return nums;
    }
};


//也可通过max_element(), min_element()实现, 见 pro_cptition_skills