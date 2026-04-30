class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size(), left = 0;
        vector<int> ans;
        vector<int> cnt_p(26);
        for (char c : p) {
            cnt_p[c - 'a']++;
        }
        vector<int> cnt_s(26);
        for (int i = 0; i < s.size(); i++) {
            int left = i - p.size() + 1;
            //进入窗口
            cnt_s[s[i] - 'a']++;
            if (left < 0) {
                left++;
                continue;
            }
            //更新答案
            if (cnt_s == cnt_p) {
                ans.push_back(left);
            }
            //离开窗口
            cnt_s[s[left] - 'a']--;
            left++;
        }
        return ans;
    }
};





















// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int nm = p.size(), left = 0;
//         vector<int> ans;
//         unordered_set<char> st(p.begin(), p.end());
//         unordered_set<char> res;
//         for (int right = 0; right < s.size(); right++) {
//             if (st.find(s[right]) != st.end()) {
//                 while (res.find(s[right]) != res.end()) {
//                     res.erase(s[left]);
//                     left++;
//                 }
//                 res.insert(s[right]);
//                 if (right - left + 1 < nm) {
//                     continue;
//                 }
//                 ans.push_back(left);
//                 res.erase(s[left]);
//                 left++;
//             }
//             else {
//                 left = right + 1;
//                 res.clear();
//             }
//         }
//         return ans;
//     }
// };



