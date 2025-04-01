#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    vector<string> vec;
    while(cin >> word) {
        vec.push_back(word);
    }

    for(auto &mem : vec) {  //toupper()中的参数要求为char, 而非string
        for(auto &c : mem) {
            c = toupper(c);
        }
        cout << mem << endl;
    }
    return 0;
}