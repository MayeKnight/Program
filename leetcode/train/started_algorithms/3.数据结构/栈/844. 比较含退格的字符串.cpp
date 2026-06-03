class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> vecs;
        vector<char> vect;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                vecs.push_back(s[i]);
            }
            else {
                if (!vecs.empty()) {
                    vecs.pop_back();   //.pop_back(); 直接删除数组最后一个元素, 使用前要先通过 .empty() 检查数组是否为空.
                }
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '#') {
                vect.push_back(t[i]);
            }
            else {
                if (!vect.empty()) {
                    vect.pop_back();   //.pop_back(); 直接删除数组最后一个元素, 使用前要先通过 .empty() 检查数组是否为空.
                }
            }
        }
        if (vecs == vect) {
            return true;
        }
        else {
            return false;
        }
    }
};

//两个数组vecs. vect, 若不为#置入, 若为#则删除末尾