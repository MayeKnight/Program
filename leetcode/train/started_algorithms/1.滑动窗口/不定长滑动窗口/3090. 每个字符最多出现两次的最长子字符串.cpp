class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans = 0, left = 0;
        multiset<char> res;  //multiset<type> 多重集合, 允许重复元素(可以存储多个相同的值)
        for (int i = 0; i < n; i++) {
            while (res.count(s[i]) > 1) {
                res.erase(res.find(s[left]));  // .find()返回指向res中第一个s[i]的迭代器以删去第一个s[i]
                left++;
            }
            res.insert(s[i]);
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};