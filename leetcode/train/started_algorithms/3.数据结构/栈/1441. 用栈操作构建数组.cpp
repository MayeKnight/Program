class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int mx = target.back(), i = 0;
        for (int x = 1; x <= mx; x++) {
            ans.push_back("Push");
            if (x == target[i]) {
                i++;
            }
            else {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};

//x从 1 开始, 遍历到mx, 先push进数, 然后判断该数是否与target[i]一致, 
//若一致, i++, 下一轮循环, 若不一致 pop