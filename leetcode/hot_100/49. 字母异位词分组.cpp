//用哈希表分组，把排序后的字符串当作哈希表的 key，排序前的字符串加到对应的列表中（哈希表的 value）。
//最后把哈希表的所有 value 加到一个列表中返回。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(s);
        }
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};