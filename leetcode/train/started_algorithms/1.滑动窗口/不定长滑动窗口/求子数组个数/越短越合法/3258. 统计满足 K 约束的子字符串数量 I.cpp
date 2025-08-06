class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        //新方法, 字符'0', '1' 转为数字0, 1
        //除了'0' - '0' == 0, '1' - '0' == 1
        //更高效的为 s[i] & 1 == 0或1  (s[i]为'0' 或 '1')
        //因为'0'的ASCII码为00110000, 与1与运算, 即 00110000 & 00000001 = 00000000  (0)
        //因为'1'的ASCII码为00110000, 与1与运算, 即 00110001 & 00000001 = 00000001  (0)
        //&1 为按位与运算会保留数字的最低位(最右边一位), 其他全部置0
        vector<int> res(2);
        int left = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            //进入窗口
            res[s[i] & 1]++;
            //满足窗口条件
            while (res[0] > k && res[1] > k) {
                //收缩左边界
                res[s[left] & 1]--;
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};