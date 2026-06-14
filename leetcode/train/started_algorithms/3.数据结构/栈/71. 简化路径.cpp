class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        vector<string> stk;

        string token;
        while (getline(ss, token, '/')) {
            if (token == ".") {
                continue;
            }
            if (token.empty()) {
                continue;
            }
            if (token == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            }
            else {
                stk.push_back(token);
            }
        }

        string ans;

        if (stk.empty()) {       //stk为空时特殊处理
            ans.push_back('/');
        }

        for (string& s : stk) {
            ans += '/';
            ans += s;
        }

        return ans;
    }
};














// class Solution {
// public:
//     string simplifyPath(string path) {
//         string ans;
//         int cnt = 0;
//         for (int i = 0; i < path.size(); i++) {
//             if (path[i] != '/') {
//                 cnt = 0;
//             }
//             if (cnt != 0) {
//                 continue;
//             }
//             if (path[i] == '/') {
//                 ans.push_back('/');
//                 cnt++;
//             }
//             if (path[i] == '.') {
//                 if (i < path.size() - 1 && path[i + 1] == '.') {
//                     if (i < path.size() - 2 && path[i + 2] == '.') {
//                         while (path[i] == '.') {
//                             ans.push_back('.');
//                             i++;
//                         }
//                         i--;
//                     }
//                     else {
//                         if (ans.size() != 1) {
//                             ans.pop_back();
//                         }
//                         while (ans.back() != '/') {
//                             ans.pop_back();
//                         }
//                         if (ans.size() != 1) {
//                             ans.pop_back();
//                         }
//                         i += 1;

//                     }
//                 }
//                 else {
//                     continue;
//                 }
//             }
//             if (path[i] != '.' && path[i] != '/') {
//                 ans.push_back(path[i]);
//             }
//         }
//         while (ans.size() != 1 && ans.back() == '/') {
//             ans.pop_back();
//         }
//         return ans;
//     }
// };

