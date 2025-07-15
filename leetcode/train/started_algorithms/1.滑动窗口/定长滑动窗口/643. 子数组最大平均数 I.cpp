class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e5, average = 0, sum = 0;  //如果所有元素为负数, 则ans可能也为负数, 故这里ans不能初始化为0， 而英初始化为一个很小的数, 
        for (int i = 0; i < nums.size(); i++) {    //并且float精度只有六到七位十进制, 较为接近10的五次方, 故应改用double，精度更高(15到16位十进制)
            // 进入窗口
            sum += nums[i];
            if (i < k - 1) {
                continue;
            }
            average = sum / k;
            //更新答案
            ans = max(ans, average);
            //离开窗口
            sum -= nums[i - k + 1];
        }
        return ans;
    }
};