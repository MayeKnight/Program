class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;  // vowel 为元音
        for (int i = 0; i < s.size(); i++) {
            // 进入窗口
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vowel++;
            if (i < k - 1)
                continue;
            // 更新答案
            ans = max(ans, vowel);
            // 离开窗口
            char out = s[i - k + 1];
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u') {
                vowel--;
            }
        }
        return ans;
    }
};