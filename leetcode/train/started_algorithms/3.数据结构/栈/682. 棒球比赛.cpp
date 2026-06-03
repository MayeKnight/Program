class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> a;  //双引号为 string 字符串, 这里直接 x[0] 表示第一个字符即可, 变为 char 类型, switch表达式必须是整形, 字符型, 枚举型, (而不能是 float/double, string, 指针), 故在下面的 switch 语句中, 要用单引号, 类似于 case '5': 
        for (string x : operations) {
            switch (x[0]) {
            case '+':
                a.push_back(a[a.size() - 2] + a.back());  //前两次得分之和
                break;
            case 'D':
                a.push_back(a.back() * 2);
                break;
            case 'C':
                a.pop_back();
                break;
            default:
                a.push_back(stoi(x));
            }
        }
        return reduce(a.begin(), a.end());
    }
};