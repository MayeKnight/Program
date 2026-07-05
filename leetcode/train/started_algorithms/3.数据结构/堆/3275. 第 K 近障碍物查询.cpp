class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        int res = 0, cnt = 0;
        for (int i = 0; i < queries.size(); i++) {
            res = abs(queries[i][0]) + abs(queries[i][1]);
            if (pq.size() == k) {
                ans.push_back(pq.top());
                if (res < pq.top()) {
                    pq.pop();
                    pq.push(res);
                }
            }
            else {
                pq.push(res);
                if (cnt) {
                    ans.push_back(-1);
                }
                cnt = 1;
            }
        }
        if (pq.size() == k) {
            ans.push_back(pq.top());
        }
        else {
            ans.push_back(-1);
        }
        return ans;
    }
};