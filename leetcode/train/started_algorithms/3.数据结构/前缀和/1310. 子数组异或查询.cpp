class Solution {
public:
    int sol(vector<int>& res, int left, int right) {
        return res[right + 1] ^ res[left];
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> res(arr.size() + 1);

        for (int i = 0; i < arr.size(); i++) {
            res[i + 1] = res[i] ^ arr[i];
        }

        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(sol(res, queries[i][0], queries[i][1]));
        }

        return ans;
    }
};


