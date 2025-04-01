#include <iostream>
#include <string>

using namespace std;

int main() {
    string line1 = "aa bb", line2 = "cc dd";
    string line3 = line1 + " " +"mdzz" + " " + line2;   //必须是string+string或string+字面量的形式，字面量+字面量如“aaa” + “bbb” 会报错
    cout << line3 << endl;
    return 0;
}