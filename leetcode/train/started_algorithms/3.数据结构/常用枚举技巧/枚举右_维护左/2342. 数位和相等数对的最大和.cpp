class Solution {
public:
    int f(int num) {
        int sum = 0;
        for (int i = num; i > 0; i /= 10) {
            sum += i % 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        sort(nums.begin(), nums.end());
        map<int, int> res;
        for (int i = n - 1; i >= 0; i--) {
            if (res.find(f(nums[i])) != res.end()) {
                ans = max(ans, nums[i] + res[f(nums[i])]);
            }
            else {
                res[f(nums[i])] = nums[i];
            }
        }
        return ans;
    }
};


//法2  (超出时间限制, 建议仍用sort(arr.begin(), arr.end()))
class Solution {
public:
    int f(int num) {
        int sum = 0;
        for (int i = num; i > 0; i /= 10) {
            sum += i % 10;
        }
        return sum;
    }
    int Partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= pivot)
                high--;
            nums[low] = nums[high];

            while (low < high && nums[low] <= pivot)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
    void QuickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivotpos = Partition(nums, low, high);
            QuickSort(nums, low, pivotpos - 1);
            QuickSort(nums, pivotpos + 1, high);
        }
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        // sort(nums.begin(), nums.end());
        QuickSort(nums, 0, nums.size() - 1);
        map<int, int> res;
        for (int i = n - 1; i >= 0; i--) {
            if (res.find(f(nums[i])) != res.end()) {
                ans = max(ans, nums[i] + res[f(nums[i])]);
            }
            else {
                res[f(nums[i])] = nums[i];
            }
        }
        return ans;
    }
};