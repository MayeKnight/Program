class RideSharingSystem {
public:
    queue<int> ride;
    queue<int> driv;
    unordered_set<int> cnt;
    RideSharingSystem() {

    }

    void addRider(int riderId) {
        ride.push(riderId);
        cnt.insert(riderId);
    }

    void addDriver(int driverId) {
        driv.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        vector<int> ans;
        while (!ride.empty() && cnt.find(ride.front()) == cnt.end()) {
            ride.pop();
        }
        if (!ride.empty() && !driv.empty()) {
            ans.push_back(driv.front());
            ans.push_back(ride.front());
            driv.pop();
            ride.pop();
        }
        else {
            return { -1, -1 };
        }
        return ans;
    }

    void cancelRider(int riderId) {  //queue没有提供查询或删除队列中指定元素的方法, 只能破坏性遍历或使用辅助队列, 故这里尝试采用其他方法, 这里采用, 另外创建一个unordered_set记录当前还有哪些rider(即队列中还有哪些rider是有效的), 执行前通过while循环检查队列.front(), 即队头元素是否存在于unordered_set中, 若unordered_set中不存在该rider, 则在循环体中循环删除 队列.front()
        cnt.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */