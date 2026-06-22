class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while (k--) {
            auto it = max_element(gifts.begin(), gifts.end());
            gifts[it - gifts.begin()] = sqrt(*it);
        }
        long long sum = reduce(gifts.begin(), gifts.end(), 0LL);
        return sum;
    }
};