#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> vec;
    while(cin >> n) {
        vec.push_back(n);
    }

    for(auto i : vec) {
        cout << i << " ";
    }
    return 0;
}