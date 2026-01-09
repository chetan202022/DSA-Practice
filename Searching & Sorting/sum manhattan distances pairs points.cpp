
// https://www.geeksforgeeks.org/dsa/sum-manhattan-distances-pairs-points/

#include <bits/stdc++.h>
using namespace std;

// Return the sum of distance of one axis.
int distancesum(vector<int> arr, int n)
{
    // sorting the array.
    sort(arr.begin(), arr.end());

    // for each point, finding the distance.
    int res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        res += (arr[i] * i - sum);
        sum += arr[i];
    }

    return res;
}

int totaldistancesum(vector<int> x, vector<int> y, int n)
{
    // Adding the distances along x and y axis. 
    return distancesum(x, n) + distancesum(y, n);
}

int main()
{
    vector<int> x = { -1, 1, 3, 2 };
    vector<int> y = { 5, 6, 5, 3 };
    int n = x.size();
    cout << totaldistancesum(x, y, n) << endl;
    return 0;
}
