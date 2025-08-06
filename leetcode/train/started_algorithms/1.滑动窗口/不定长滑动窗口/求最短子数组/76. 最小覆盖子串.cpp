class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> res;
        long long  min_len = INT_MAX, start = 0, left = 0;

        for (char c : t) res[c]++;
        long long count = res.size();

        for (int i = 0; i < s.size(); i++) {
            if (res.find(s[i]) != res.end()) {
                res[s[i]]--;
                if (res[s[i]] == 0) {  //如果这个if不在 查找s[i]的这个if中的话, 在判断res[s[i]]是否为0时, 如果s[i]不在res中, 就会先创建一个键为s[i]的键值对并赋为0再与0比较, 就会导致count错误的减一, 所以这里必须先查找s[i]确定存在, 再进行if(res[s[i]] == 0) count--的操作
                    count--;
                }
            }
            while (count == 0) {
                if (i - left + 1 < min_len) {
                    min_len = i - left + 1;
                    start = left;
                }
                if (res.find(s[left]) != res.end()) {
                    res[s[left]]++;
                    if (res[s[left]] == 1) {
                        count++;
                    }
                }
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};