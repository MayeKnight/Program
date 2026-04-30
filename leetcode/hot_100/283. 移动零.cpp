class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int stack_size = 0;
        for (int x : nums) {
            if (x) {
                nums[stack_size++] = x;   //把x入栈
            }
        }
        fill(nums.begin() + stack_size, nums.end(), 0);
    }
};