class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double ans = 0, average = 0, sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            // 进入窗口
            sum += arr[i];
            if (i < k - 1) {
                continue;
            }
            average = sum / k;
            //更新答案
            if (average >= threshold) {
                ans++;
            }
            //离开窗口
            sum -= arr[i - k + 1];
        }
        return ans;
    }
};