#include <iostream>
#include <string>

using namespace std;

int main() {
    string line1 = "aa bb", line2 = "cc dd";
    if(line1 > line2) {
        cout << line1 << endl;
    }
    else {
        cout << line2 << endl;
    }
    return 0;
}