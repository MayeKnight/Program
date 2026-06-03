class Solution {
public:
    string removeStars(string s) {
        string ans;  // 实质上, string 可以理解为一种专门存储字符的容器(用法类似于vector)
        for (auto& x : s) {  //s为string类型, 故这里x为s[0],s[1]对应的char类型, 符合switch语句的要求
            switch (x) {
            case '*':
                ans.pop_back();
                break;
            default:
                ans.push_back(x);
            }
        }
        return ans;
    }
};