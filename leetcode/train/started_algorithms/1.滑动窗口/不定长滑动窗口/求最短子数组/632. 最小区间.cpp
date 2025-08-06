//典型的排序+滑动窗口的解法
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> res;                                 //pair<type, type> p; 是C++STL的实用模板类, 这里用于将两个整数组合成单一对象, p.first访问第一个元素, p.second访问第二个元素.
        for (int i = 0; i < nums.size(); i++) {                       //nums.size()返回的是二维数组行的数量, nums[0].size返回二维数组中第0行有几个元素
            for (auto n : nums[i]) res.push_back({ n, i });            //n为实际值, i为数组位序
        }
        sort(res.begin(), res.end());                               //sort默认会对pair<int, int>的两个元素(first和second)进行字典序排序, 即先按first排序, 若first相同, 再按second排序。得到[(0,1),(4,0),(5,2),(9,1),(10,0),(12,1)]


        unordered_map<int, int> con;
        int left = 0;
        int count = 0; //当前窗口覆盖的独特列表数
        int min_len = INT_MAX;
        vector<int> result;

        for (int right = 0; right < res.size(); right++) {
            //扩展右边界
            if (con[res[right].second]++ == 0) {
                count++;
            }

            //当窗口包含所有列表时
            while (count == nums.size()) {
                //计算当前窗口长度
                int current_len = res[right].first - res[left].first;
                if (current_len < min_len) {
                    min_len = current_len;
                    result = { res[left].first, res[right].first };
                }

                //收缩左边界
                if (--con[res[left].second] == 0) {
                    count--;
                }
                left++;
            }
        }

        return result;
    }
};






// pair<>的声明和初始化
// // 默认构造函数
// pair<int, int> p1; // 两个int都被初始化为0

// // 使用make_pair函数
// pair<int, int> p2 = make_pair(10, 20);

// // 使用初始化列表 (C++11及以上)
// pair<int, int> p3 = {30, 40};

// // 直接构造
// pair<int, int> p4(50, 60);