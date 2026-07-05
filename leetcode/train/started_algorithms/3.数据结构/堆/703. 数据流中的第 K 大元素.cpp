class KthLargest {
private:
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> pq;    //维护一个小顶堆, 使其大小保持为k, 此时堆顶即为第k大元素

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        if (nums.size() != 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (pq.size() == k) {
                    if (nums[i] > pq.top()) {
                        pq.pop();
                        pq.push(nums[i]);
                    }
                }
                else {
                    pq.push(nums[i]);
                }
            }
        }
    }

    int add(int val) {
        if (pq.size() == k) {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        else {
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */




 // class KthLargest {
 // public:
 //     vector<int> v;
 //     int res = 0;
 //     KthLargest(int k, vector<int>& nums) {
 //         for (int i = 0; i < nums.size(); i++) {
 //             v.push_back(nums[i]);
 //             push_heap(v.begin(), v.end());
 //         }
 //         res = k;
 //     }

 //     int add(int val) {
 //         v.push_back(val);
 //         push_heap(v.begin(), v.end());
 //         while (res--) { // 错误, add调用会导致res被永久修改, 下次调用add时, res = 0, 不再执行.
 //             pop_heap(v.begin(), v.end());
 //             v.pop_back();
 //         }
 //         return v[0];
 //     }
 // };

 // /**
 //  * Your KthLargest object will be instantiated and called as such:
 //  * KthLargest* obj = new KthLargest(k, nums);
 //  * int param_1 = obj->add(val);
 //  */