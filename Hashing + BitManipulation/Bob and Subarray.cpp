
// https://www.hackerrank.com/contests/codeagon/challenges/bob-and-subarray-or

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long sumBitwiseOR(vector<int>& arr){

    int n = arr.size();
    long long total = (1LL * n * (n + 1)) / 2;
    long long ans = 0;

    for(int bit = 0; bit < 32; bit++){

        long long zero_sub = 0;
        long long len = 0;

        for(int i = 0; i < n; i++){

            if(arr[i] & (1LL << bit)){
                zero_sub += (len * (len + 1)) / 2;
                len = 0;
            }
            else{
                len++;
            }
        }

        zero_sub += (len * (len + 1)) / 2;

        long long one_sub = total - zero_sub;

        ans += one_sub * (1LL << bit);
    }

    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    long long ans = sumBitwiseOR(arr);
    cout << ans << endl;
    return 0;
}
