class Solution {
public:
    long long solve(string word, int k) {
        unordered_map<char, int> res;
        long long ans = 0, left = 0, con = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                res[word[i]]++;
            }
            else {
                con++;
            }
            while (res.size() == 5 && left <= i && con >= k) {
                if (word[left] == 'a' || word[left] == 'e' || word[left] == 'i' || word[left] == 'o' || word[left] == 'u') {
                    if (--res[word[left]] == 0) {
                        res.erase(word[left]);
                    }
                }
                else {
                    con--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        if (word.size() <= 0 || k < 0) {
            return 0;
        }
        return solve(word, k) - solve(word, k + 1);
    }
};