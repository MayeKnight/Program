using ll = long long;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //可以把左侧k个元素和右侧k个元素放到新的数组中把问题转化为固定长度为k的滑动窗口, 求最大和
        //构建新数组
        vector<ll> points;
        ll m = cardPoints.size();
        for (ll i = k - 1; i >= 0; i--) {
            points.push_back(cardPoints[i]);
        }
        for (ll i = m - 1; i >= m - k; i--) {
            points.push_back(cardPoints[i]);
        }
        ll n = points.size(), sum = 0, cur = 0;
        for (ll i = 0; i < n; i++) {
            //进入窗口
            cur += points[i];
            if (i < k - 1) {
                continue;
            }
            //更新答案
            sum = max(cur, sum);
            //离开窗口
            cur -= points[i - k + 1];
        }
        return sum;
    }
};