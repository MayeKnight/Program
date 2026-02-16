class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = -1, n = cards.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(cards[i]) != mp.end()) {
                if (ans < abs(i - mp[cards[i]])) {
                    ans = abs(i - mp[cards[i]]) + 1;
                }
                else {
                    mp[cards[i]] = i;
                }
            }
            else {
                mp[cards[i]] = i;
            }
        }
        return ans;
    }
};