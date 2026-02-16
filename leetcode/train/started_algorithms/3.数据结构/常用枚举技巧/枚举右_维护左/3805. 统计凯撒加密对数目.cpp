class Solution {
public:
    string f(string& s) {
        for (auto& c : s) {
            if (c != 'z') {
                c = c + 1;
            }
            else {
                c = 'a';
            }
        }
        return s;
    }
    long long countPairs(vector<string>& words) {
        long long n = words.size(), ans = 0, cnt = 0;
        unordered_map<string, long long> mp;
        mp[words[0]]++;
        for (int i = 1; i < n; i++) {
            if (mp.find(words[i]) != mp.end()) {
                mp[words[i]]++;
            }
            else {
                for (int j = 0; j < 26; j++) {
                    f(words[i]);
                    if (mp.find(words[i]) != mp.end()) {
                        mp[words[i]]++;
                        cnt = 1;
                        break;
                    }
                }
                if (cnt != 1) {
                    mp[words[i]]++;
                }
                else {
                    cnt = 0;
                }
            }
        }
        for (auto& pair : mp) {
            ans += pair.second * (pair.second - 1) / 2;
        }
        return ans;
    }
};