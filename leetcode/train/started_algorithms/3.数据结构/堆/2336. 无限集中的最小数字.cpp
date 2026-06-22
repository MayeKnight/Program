class SmallestInfiniteSet {
public:
    vector<int> v;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            v.push_back(i);
            push_heap(v.begin(), v.end(), greater<int>());
        }
    }

    int popSmallest() {
        int res = 0;
        if (!v.empty()) {
            pop_heap(v.begin(), v.end(), greater<int>());
            res = v.back();
            v.pop_back();
            return res;
        }
        return 0;
    }

    void addBack(int num) {
        auto it = find(v.begin(), v.end(), num);
        if (it == v.end()) {
            v.push_back(num);
            push_heap(v.begin(), v.end(), greater<int>());
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */