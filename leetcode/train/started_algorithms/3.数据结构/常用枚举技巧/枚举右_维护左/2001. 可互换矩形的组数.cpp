class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long n = rectangles.size(), ans = 0;
        vector<double> res;
        map<double, long long> mp;
        for (long long i = 0; i < n; i++) {
            //static_cast用于将整数int类型强制转换为浮点数double类型, C++常用
            res.push_back(static_cast<double>(rectangles[i][0]) / rectangles[i][1]);
        }
        for (long long i = 0; i < n; i++) {
            if (mp.find(res[i]) != mp.end()) {
                ans += mp[res[i]];
                mp[res[i]]++;
            }
            else {
                mp[res[i]]++;
            }
        }
        return ans;
    }
};