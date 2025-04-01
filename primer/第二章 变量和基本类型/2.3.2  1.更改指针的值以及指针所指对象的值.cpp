#include <iostream>

using namespace std;

int main() {
    int a = 10, b = 11, *p1 = &a, *p2 = &b;
    *p1 = 12;
    cout << *p2 << endl;
    *p2 = a;
    cout << *p1 << " " << *p2 << endl;
    return 0;
}