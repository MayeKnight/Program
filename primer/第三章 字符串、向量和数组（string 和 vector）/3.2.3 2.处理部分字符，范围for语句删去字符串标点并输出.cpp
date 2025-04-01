#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World!!";
    for(decltype(s.size()) index = 0; index != s.size(); index++) {
        if(ispunct(s[index])){
            s[index] = ' ';
        }
    }
    cout << s << endl;
    return 0;
}