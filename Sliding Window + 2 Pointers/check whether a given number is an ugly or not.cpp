
// https://www.geeksforgeeks.org/dsa/check-whether-a-given-number-is-an-ugly-number-or-not/

#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is an ugly number or not
int isUgly(int n)
{
    // Base Cases
    if (n == 1)
        return 1;
    if (n <= 0)
        return 0;

    // Condition to check if the number is divided by 2, 3,
    // or 5
    if (n % 2 == 0)
        return isUgly(n / 2);
    if (n % 3 == 0)
        return isUgly(n / 3);
    if (n % 5 == 0)
        return isUgly(n / 5);

    // Otherwise return false
    return 0;
}
// Driver Code
int main()
{
    int no = isUgly(14);
    if (no == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
