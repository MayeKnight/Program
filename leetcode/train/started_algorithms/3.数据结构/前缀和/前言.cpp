"讲解"前缀和
使用实例见"D:\Tech\Code\Program\leetcode\train\started_algorithms\3.数据结构\前缀和\303. 区域和检索 - 数组不可变.cpp"
关键思路 :   //本文中的"子数组"均表示"连续子数组"
----
//左闭右开公式: 子数组[left, right) 的元素和为 sum[right] - sum[left].若下标区间定义成左闭右开, 就不需要如下述还要对right + 1了

比如nums = [1, 2, 3, 4, 5, 6], 要想计算子数组[3, 4, 5]的元素和, 可以用前缀[1, 2, 3, 4, 5]的元素, 减去另一个前缀[1, 2]的元素和, 就得到了子数组[3, 4, 5]的元素和, 即
3 + 4 + 5 = (1 + 2 + 3 + 4 + 5) - (1 + 2)
换句话说, 把前缀[1, 2, 3, 4, 5]的前缀[1, 2]去掉, 就得到了子数组[3, 4, 5]

一般的, 任意子数组都是一个前缀去掉前缀后的结果, 所以"任意子数组的和, 都可以表示为两个前缀和的差"

nums 的子数组有 O(n ^ 2) 个, 但只有 O(n) 个前缀, 那么预处理 nums 的所有前缀和, 就可以 O(1) 计算任意子数组的元素和
----


具体思路:
为方便描述, 把 nums 记作 a, 设其长度为 n
对于数组 a, 计算它的长为 n + 1 的前缀和数组 s, 即 a 的前0个数的和, 前1个数的和, 前2个数的和...前n个数的和.
s[0] = 0
s[1] = a[0]
s[2] = a[0] + a[1]
...
s[i] = a[0] + a[1] + ... + a[i - 1]
...
s[n] = a[0] + a[1] + ... + a[n - 1]
根据这个定义, 前i个数的和, 加上 a[i], 就是前 i + 1 个数的和
即 s[i + 1] = s[i] + a[i]

示例中的数组[-2, 0, 3, -5, 2, -1], 对应的前缀和数组 s = [0, -2, -2, 1, -4, -2, -3]
通过前缀和, 我们可以把子数组的元素转化成两个前缀和的差, 下标区间[left, right]的元素和等于前缀[0, right]的元素和减去另一个前缀[0, left - 1]的元素和, 即
s[right + 1] - s[left]
有了这个式子, 示例中子数组[3, -5, 2, -1]的和([2, 5]), 就可以 O(1) 地用 s[6] - s[2] 算出来

//关于为什么定义 s[0] = 0, 是因为如果 left = 0, 要计算的数组是一个前缀(从a[0]到a[right]). 按照公式, 我们要用a[right + 1]减去s[0], 而如果不定义 s[0] = 0, 就要特判 left = 0 的情况了

//不一定要用到下述思路，前缀和是一种算法思想，灵活应用
//eg.见"D:\Tech\Code\Program\leetcode\train\started_algorithms\3.数据结构\前缀和\3152. 特殊数组 II.cpp"

//求[left, right]的元素和, 这种表述下则为 前缀和[right + 1] - 前缀和[left]

//注意, 前缀和应写到主函数中, 而不要写到其他函数中, 避免因为在主函数中写的循环中, 调用含有前缀和的其他函数, 而导致反复计算前缀和的情况发生, 否则可能导致超时
class Solution {
public:
    // 注意使用 const，效率差异
    // 你的引用呢？？？？？ vector<int> 直接复制？？？？？  就是&
    int sol(const vector<int>& res, int left, int right) {
        return res[right + 1] - res[left];
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        vector<int> res(words.size() + 1);
        // const string vowels = "aeiou";
        //在主函数中计算前缀和, 而不要写到其他函数中, 比如上面的sol()函数, 避免因为在主函数中写的循环中调用含有前缀和的其他函数, 而导致反复计算前缀和的情况发生而超时
        for (int i = 0; i < words.size(); i++) {
            if ((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') && (words[i][words[i].size() - 1] == 'a' || words[i][words[i].size() - 1] == 'e' || words[i][words[i].size() - 1] == 'i' || words[i][words[i].size() - 1] == 'o' || words[i][words[i].size() - 1] == 'u')) {
                res[i + 1] = res[i] + 1;
            }
            else {
                res[i + 1] = res[i];
            }
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(sol(res, queries[i][0], queries[i][1]));
        }
        return ans;
    }
};




