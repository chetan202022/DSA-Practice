
// https://www.naukri.com/code360/problems/distinct-characters_2221410

#include <bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    unordered_map<char, int> mp;

    int l=0, ans=0;

    for(int r=0; r<str.size(); r++){
        mp[str[r]]++;

        while(mp.size() > k){
            mp[str[l]]--;
            if(mp[str[l]] == 0) mp.erase(str[l]);
            l++;
        }

        ans = max(ans, (r-l+1));
    }
    return ans;
}


