class FrontMiddleBackQueue {
public:
    deque<int> dq;
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        dq.push_front(val);
    }

    void pushMiddle(int val) {
        auto it = dq.begin() + dq.size() / 2;
        dq.insert(it, val);
    }

    void pushBack(int val) {
        dq.push_back(val);
    }

    int popFront() {
        if (!dq.empty()) {
            int x = dq.front();
            dq.pop_front();
            return x;
        }
        else {
            return -1;
        }
    }

    int popMiddle() {
        if (!dq.empty()) {
            auto it = dq.begin() + (dq.size() - 1) / 2;
            int x = dq[(dq.size() - 1) / 2];
            dq.erase(it);
            return x;
        }
        else {
            return -1;
        }
    }

    int popBack() {
        if (!dq.empty()) {
            int x = dq.back();
            dq.pop_back();
            return x;
        }
        else {
            return -1;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */