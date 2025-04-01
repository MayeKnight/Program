#include <iostream>
#include <string>
using namespace std;

// Define the data structure for each element
struct ElemType {
    int Key;
    string Content;
};

// Define the sequential list structure
struct SqList {
    ElemType data[20];
    int length;
};

// Function to create the sequential list
void Create_Sq(SqList &L) {
    int n;
    cout << "请输入数据个数,不超过20个: ";
    cin >> n;
    L.length = n;
    cout << "请输入待排序的数据: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> L.data[i].Key;
        L.data[i].Content = "刘旭东" + to_string(i+1); // Set the Content
    }
}

// Function to display the sequential list
void show(SqList L) {
    cout << "当前表的结果为: " << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i].Key << " " << L.data[i].Content << endl;
    }
}

int main() {
    SqList L; // Create an instance of the sequential list
    Create_Sq(L); // Create the sequential list
    show(L); // Display the sequential list
    return 0;
}