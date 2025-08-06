class Solution {
public:
    int balancedString(string s) {
        //通过替换一个子串，可以调整字符的计数。替换的子串可以是任何字符，因此我们需要找到一个子串，使得在移除该子串后，剩下的各个字符的计数不超过 n/4，这样可以通过替换子串来补足不足的部分。
        int n = s.size(), tar = n / 4, ans = 1e9, left = 0;
        unordered_map<char, int> sum;
        for(int i = 0; i < n; i++){
            sum[s[i]]++;
        }
        if (sum['Q'] == tar && sum['W'] == tar && sum['E'] == tar && sum['R'] == tar) {
            return 0; // 已经符合要求啦
        }
        for(int i = 0; i < n; i++){
            sum[s[i]]--; //这里实际含义是减去窗口字符
            while(sum['Q'] <= tar && sum['W'] <= tar && sum['E'] <= tar && sum['R'] <= tar){
                ans = min(ans, i - left + 1);
                sum[s[left]]++; //缩小子串, 从窗口放出字符
                left++;
            }
        }
        return ans;
    }
};