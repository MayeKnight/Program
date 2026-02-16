class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
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

    void QuickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivotpos = Partition(nums, low, high);
            QuickSort(nums, low, pivotpos - 1);
            QuickSort(nums, pivotpos + 1, high);
        }
    }

    int f(string& s) {
        int cnt = 0;
        char ch = 'z';
        for (auto c : s) {
            if (c < ch) {
                ch = c;
                cnt = 1;
            }
            else if(c == ch) {
                cnt++;
            }
        }
        return cnt;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        vector<int> que;
        vector<int> word;
        for (int i = 0; i < queries.size(); i++) {
            que.push_back(f(queries[i]));
        }
        for (int i = 0; i < words.size(); i++) {
            word.push_back(f(words[i]));
        }
        QuickSort(word, 0, word.size() - 1);
        for (int i = 0; i < que.size(); i++) {
            res.push_back(word.size() - lower_bound(word, que[i] + 1));
        }
        return res;
    }
};