class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;  //避免溢出
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr2);  //排序arr2
        int start = -1, end = 0, ans = 0;
        for (int i = 0; i < arr1.size(); i++) {
            end = lower_bound(arr2, arr1[i]);
            if (end >= 1) {
                start = lower_bound(arr2, arr1[i]) - 1;
            }
            if (end == arr2.size()) {
                if (abs(arr1[i] - arr2[end - 1]) > d) {
                    ans++;
                }
            }
            else if (start != -1) {
                if (abs(arr1[i] - arr2[end]) >= abs(arr1[i] - arr2[start])) {
                    if (abs(arr1[i] - arr2[start]) > d) {
                        ans++;
                    }
                }
                else {
                    if (abs(arr1[i] - arr2[end]) > d) {
                        ans++;
                    }
                }
            }
            else {
                if (abs(arr1[i] - arr2[end]) > d) {
                    ans++;
                }
            }
            start = -1;
        }
        return ans;
    }
};


//法二
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;  //避免溢出
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr2);  //排序arr2
        int end = 0, ans = 0;
        for (int i = 0; i < arr1.size(); i++) {
            end = lower_bound(arr2, arr1[i]);
            bool value = true;

            //检查右边的元素, 如果元素存在
            if (end < arr2.size()) {
                if (abs(arr2[end] - arr1[i]) <= d) {
                    value = false;
                }
            }

            //检查左边的元素, 如果元素存在
            if (end > 0) {
                if (abs(arr2[end - 1] - arr1[i]) <= d) {
                    value = false;
                }
            }

            if (value) {
                ans++;
            }
        }
        return ans;
    }
};