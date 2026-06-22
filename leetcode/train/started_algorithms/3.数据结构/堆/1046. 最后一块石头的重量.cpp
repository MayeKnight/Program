class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int m = 0, n = 0, res = 0;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while (pq.size() > 1) {
            m = pq.top();
            pq.pop();
            n = pq.top();
            pq.pop();
            res = abs(m - n);
            if (res != 0) {
                pq.push(res);
            }
        }
        if (pq.size() == 0) {
            return 0;
        }
        else {
            return pq.top();
        }
    }
};