class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> a;
        int rec = 0;
        for (int i = 0; i < pushed.size(); i++) {
            a.push_back(pushed[i]);
            while (!a.empty() && a.back() == popped[rec]) {  //!a.enpty()保证栈不为空时才访问a.back(), 否则会出现未定义而报错 (这里是用vector<int> 来模拟栈)
                a.pop_back();
                rec++;
            }
        }
        if (a.empty()) {
            return true;
        }
        return false;
    }
};