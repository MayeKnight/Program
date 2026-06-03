class BrowserHistory {
public:
    vector<string> a;
    int rec = -1;

    BrowserHistory(string homepage) {  //题意, 初始化
        a.push_back(homepage);
        rec++;
    }

    void visit(string url) {
        rec++;
        a.resize(rec);  //.resize()函数 可以用于保留前cur个元素(下标从 0 到 cur - 1), 删除下标 cur 及之后的所有元素.
        a.push_back(url);
    }

    string back(int steps) {
        if (steps > rec) {
            rec = 0;
            return a[rec];
        }
        else {
            rec -= steps;
            return a[rec];
        }
    }

    string forward(int steps) {  //a.size()-1 = 2  rec=1, steps = 1
        if (steps + rec > a.size() - 1) {
            rec = a.size() - 1;
            return a[rec];
        }
        else {
            rec += steps;
            return a[rec];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */