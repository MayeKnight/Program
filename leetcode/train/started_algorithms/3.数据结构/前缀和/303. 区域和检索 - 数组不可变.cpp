class NumArray {
    vector<int> res;
public:
    NumArray(vector<int>& nums) {
        res.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            res[i + 1] += res[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return res[right + 1] - res[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */