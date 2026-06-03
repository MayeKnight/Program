class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = a[i] + nums[i];
        }
        unordered_map<int, int> cnt;
        for (int aj : a) {
            if (cnt.find(aj - k) != cnt.end()) {
                ans += cnt[aj - k];
            }
            cnt[aj]++;
        }
        return ans;
    }
};


a[j] - a[i] = k
a[j] - k = a[i]
遍历a, 找a[j] - k, 存 ans += cnt[aj - k]
存aj - k












// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         long long n = nums.size(), ans = 0;
//         vector<long long> a(n + 1);
//         unordered_map<long long, long long> mp;
//         if (n == 1) {
//             if (nums[0] == k) {
//                 return 1;
//             }
//             else {
//                 return 0;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             a[i + 1] = a[i] + nums[i];
//             mp[a[i + 1]]++;                    // 0 -1 -2 -1
//         }                                      // 1  2  1  2
//         mp[0]++;
//         for (int i = 0; i < n + 1; i++) {
//             if (i < n && nums[i] == k) {
//                 ans++;
//                 continue;
//             }
//             if (i != 0) {
//                 mp[a[i]]--;           // 
//             }
//             if (mp[a[i]] == 0) {     //
//                 mp.erase(a[i]);
//             }
//             if (mp.find(k + a[i]) != mp.end()) {  //
//                 if (k == 0 && i == 0) {
//                     continue;
//                 }
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };


//元素自身.  3=k=3
// 2-0, 3-1

// s1 - s2 = k

// 1 2 3 4

// 1 3 6 10  k = 5
// 5 + 1 = 6

// 前缀和a, 置入哈希
// 遍历前缀和, 到a[i]  hash[a[i]]--, if (hash[a[i]] == 0) hash.erase(a[i])  
//k + a[i] exist ?  exist ans++
