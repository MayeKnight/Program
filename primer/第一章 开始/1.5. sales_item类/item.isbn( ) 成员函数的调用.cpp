#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
    int cnt = 0;
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if(item1.isbn == item2.isbn) {
        cnt++;
    }
    cout << cnt;
    return 0;
}