// const string vowels = "aeiou";
        // if (vowels.contains(s[i])) {
        //
        // }
        // 你先自己写，写完再然后看我注释，调整
        //哦, 是前缀和
        //??什么喵？???
        //我这个是不是太麻烦了喵》
        //哦，忘了..??哦
        //运行过, 提交超出时间限制, 怎么办awa 93/94


/*

你这前缀和写得有意义吗？每次遍历都要计算一遍前缀和？？
有吗？？awa
沙币？
怎么写欸？？

你再想想，每次 query 进入到 sol 函数，sol 里面都去构建一个前缀和？？你图什么？
...哦~对哦
*/

class Solution {
public:
    //注意, 前缀和应写到主函数中, 而不要写到其他函数中, 避免因为在主函数中写的循环中, 调用含有前缀和的其他函数, 而导致反复计算前缀和的情况发生, 否则可能导致超时
    // 注意使用 const，效率差异
    // 你的引用呢？？？？？ vector<int> 直接复制？？？？？
    int sol(vector<int>& res, int left, int right) {
        return res[right + 1] - res[left];
    }

    // 你现在在干什么？？？？？？？？？？？？？？？？？？？？？？？？？
    // 你数组大小都不认识吗？？？？？？？？？？？？？？？？？？？？？？

    //wjh的
    // vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    //     vector<int> ans;
    //     int n = queries.size();

    //     vector<int> res(words.size() + 1); 
    //     // const string vowels = "aeiou";
    //     for(int i = 0; i < words.size(); i++){
    //         if((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') && (words[i][words[i].size() - 1] == 'a' || words[i][words[i].size() - 1] == 'e' || words[i][words[i].size() - 1] == 'i' || words[i][words[i].size() - 1] == 'o' || words[i][words[i].size() - 1] == 'u')){
    //             res[i + 1] = res[i] + 1;
    //         }//这个有问题, 等我想想
    //         else{
    //             res[i + 1] = res[i];
    //         }
    //     }
    //     for(int i = 0; i < n; i++){
    //         ans.push_back(sol(res, queries[i][0], queries[i][1]));
    //     }
    //     return ans;
    // }

    //lyl的
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const string vowels = "aeiou";

        vector<int> pre{ 0 };
        for (auto& s : words) {
            pre.push_back(pre.back());
            if (vowels.contains(s.front()) && vowels.contains(s.back())) { // C++ 20 的语法，你之后如果有上机考试，估计是不支持..嗯，可以收录下awa
                // pre[i + 1]++;  //哦哦~
                pre.back()++;
            }
        }

        // 自己提交,呱唧呱唧

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(pre[q[1] + 1] - pre[q[0]]);
        }
        return ans;
    }
};


