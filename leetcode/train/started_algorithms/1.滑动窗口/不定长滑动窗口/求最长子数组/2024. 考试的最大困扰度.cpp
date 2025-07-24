class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(str(answerKey, 'T', k), str(answerKey, 'F', k));
    }
    int str(string ak, char c, int k) {
        int n = ak.size(), ans = 0, left = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (ak[i] != c) {
                count++;
            }
            while (count > k) {
                if (ak[left] != c) {
                    count--;
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};