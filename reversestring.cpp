#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str = "Hello";

    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;
    return 0;
}