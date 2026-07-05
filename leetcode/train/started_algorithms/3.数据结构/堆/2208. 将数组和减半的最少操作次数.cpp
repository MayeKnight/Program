class Solution {
private:
    priority_queue<long double> pq;

public:
    int halveArray(vector<int>& nums) {
        long double res = reduce(nums.begin(), nums.end(), 0LL);  //0LL 告知 reduce 函数按照 long long 形式运算, 最终返回 long long 类型, 避免溢出
        long long ans = 0;
        long double mx = 0;
        long double cnt = static_cast<long double>(res) / 2;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (res > cnt) {
            if (!pq.empty()) {
                mx = pq.top();
                res -= mx / 2;
                pq.pop();
                pq.push(mx / 2);
                ans++;
            }
        }
        return ans;
    }
};