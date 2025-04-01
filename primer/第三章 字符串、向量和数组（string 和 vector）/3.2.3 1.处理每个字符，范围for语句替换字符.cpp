#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World";
    for(auto &c : s) {
        c = 'x';  //单引号用于表示字符字面量，双引号用于表示字符串字面量
    }
    cout << s << endl;
    return 0;
}