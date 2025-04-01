#include <iostream>
#include "Sales_data.h"

using namespace std;

int main() {
    double price = 0;
    Sales_data data1, data2;
    
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if(data1.bookNo == data2.bookNo) {
        unsigned totalrant = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << totalrant << " " << totalRevenue<< " " << totalRevenue / totalrant << endl;
    }
    else {
        cout << "Data must refer to the same ISBN" << endl;
    }

    return 0;
}