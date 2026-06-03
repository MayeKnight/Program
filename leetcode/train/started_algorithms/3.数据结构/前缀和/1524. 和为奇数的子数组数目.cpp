class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = a[i] + arr[i];
        }
        unordered_map<long long, long long> jh;
        unordered_map<long long, long long> oh;
        for (int i = n; i >= 0; i--) {
            jh[n + 1] = 0;
            oh[n + 1] = 0;
            if (a[i] % 2 == 1) {
                jh[i] = jh[i + 1] + 1;
            }
            else {
                jh[i] = jh[i + 1];
            }
            if (a[i] % 2 == 0) {
                oh[i] = oh[i + 1] + 1;
            }
            else {
                oh[i] = oh[i + 1];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                ans += jh[i];
            }
            if (a[i] % 2 == 1) {
                ans += oh[i];
            }
        }
        return ans % (1'000'000'000 + 7);
    }
};


0 1 4 9   //2 + 1 + 1  
0 2 6 12  //0
0 1 3 6 10 15 21 28 // 4+3+3+2+2+1+1

奇偶哈希  n = 3
原    0 1 4 9
下标  0 1 2 3
奇哈希 2 2 1 1
偶哈希 2 1 1 0   //0对应奇哈希[0]=2,1对应偶哈希[1]=1, 4对应奇哈希[2]=1
