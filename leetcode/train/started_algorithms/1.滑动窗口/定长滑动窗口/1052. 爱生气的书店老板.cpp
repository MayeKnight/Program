using ll = long long;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //要使总的满意的顾客最多，则窗口要尽可能多的将不满意的顾客变为满意
        //所以问题转化为固定长度窗口，求窗口内部不满意顾客的最大和
        ll n = customers.size(), happy = 0, angry = 0, cur = 0;
        for(ll i = 0; i < n; i++){
            if(!grumpy[i]){
                happy += customers[i];
            }
        }
        for(ll i = 0; i < n; i++){
            //进入窗口
            if(grumpy[i]){
                cur += customers[i];
            }
            if(i < minutes - 1){
                continue;
            }
            //更新答案
            angry = max(angry, cur);
            //离开窗口
            if(grumpy[i - minutes + 1]){
                cur -= customers[i - minutes + 1];
            }
        }
        return angry + happy;
    }
};