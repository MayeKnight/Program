class Solution {
public:
    int f(int i) {
        int res = 0;
        res = i * (i - 1) / 2;
        return res;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size(), ans = 0;
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++) {
            sort(dominoes[i].begin(), dominoes[i].end());
        }
        for (int i = 0; i < n; i++) {
            if (mp.find(dominoes[i]) != mp.end()) {
                mp[dominoes[i]]++;
            }
            else {
                mp[dominoes[i]] = 1;
            }
        }
        //遍历map中的值, 基于范围for循环实现
        for (auto pair : mp) {
            ans += f(pair.second);
        }
        return ans;
    }
};