//sum of the numbers
#include <iostream>
using namespace std;

int main()
{
    int n, num, sum = 0;

    cout << "Enter how many numbers: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter number " << i << ": ";
        cin >> num;
        sum = sum + num;
    }

    cout << "\nSum of the numbers = " << sum;

    return 0;
}