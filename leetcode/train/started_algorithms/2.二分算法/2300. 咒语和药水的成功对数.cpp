class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
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

    void QuickSort(vector <int>& nums, int low, int high) {
        if (low < high) {
            int pivotpos = Partition(nums, low, high);
            QuickSort(nums, low, pivotpos - 1);
            QuickSort(nums, pivotpos + 1, high);
        }
    }


    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        long long res = 0;
        // QuickSort(potions, 0, potions.size() - 1);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++) {
            res = (success + spells[i] - 1) / spells[i];  //向上取整
            // ans.push_back(potions.size() - lower_bound(potions, res));
            auto it = std::lower_bound(potions.begin(), potions.end(), res);
            ans.push_back(potions.size() - (it - potions.begin()));  //it - potions.begin()得到 >=res 的数组下标
        }
        return ans;
    }
};