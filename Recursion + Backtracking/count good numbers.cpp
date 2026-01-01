
// https://leetcode.com/problems/count-good-numbers/

class Solution {
public:
    using ll = long long;
    const int M = 1e9 + 7;
    ll pow(int a, ll b){
        if(b == 0)return 1;
        ll val = (pow(a, b/2))%M;
        if(b % 2 == 0) return (val * val)%M;
        else return (a * val * val)%M;
    }

    int countGoodNumbers(long long n) {
        ll val = n/2;
        if(n % 2 == 0){ // if n is even
            return (pow(5, val))%M * (pow(4, val))%M;
        }else{
            return (pow(5, val+1))%M * (pow(4, val))%M;
        }

    }
}; 
