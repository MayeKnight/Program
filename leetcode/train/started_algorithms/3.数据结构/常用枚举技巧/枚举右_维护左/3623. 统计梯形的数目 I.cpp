class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;
        long long res = 0, cnt = 0, ans = 0;
        unordered_map<int, int> mp;
        for (auto& p : points) {
            mp[p[1]]++;
        }
        for (auto& pair : mp) {
            res = 1LL * pair.second * (pair.second - 1) / 2;  //1LL保证了乘法在 long long 范围内进行, 避免整数溢出
            ans += res * cnt;
            cnt += res;
        }
        return ans % MOD;
    }
};