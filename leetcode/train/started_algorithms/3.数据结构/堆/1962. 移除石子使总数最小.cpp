class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        long long res = 0, ans = 0;
        vector<long long> v(piles.begin(), piles.end());
        make_heap(v.begin(), v.end());
        while (k--) {
            res = v[0] - floor(v[0] / 2);
            pop_heap(v.begin(), v.end());
            v.pop_back();
            v.push_back(res);
            push_heap(v.begin(), v.end());
        }
        return reduce(v.begin(), v.end());
    }
};