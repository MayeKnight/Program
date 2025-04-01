#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    vector<string> vec;
    while(cin >> word) {
        vec.push_back(word);
    }
    
    for(auto it = vec.begin(); it != vec.end() && !it -> empty(); it++) {
        cout << *it << endl;
    }

    return 0;
}