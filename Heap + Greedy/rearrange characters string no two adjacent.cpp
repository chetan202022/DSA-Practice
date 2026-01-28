
// https://www.geeksforgeeks.org/dsa/rearrange-characters-string-no-two-adjacent/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to rearrange character of a string
// so that no two adjacent characters are same
string rearrangeString(string &s) {
    int n = s.length();
    int mxCnt = 0;
    char ch = '#';

    // Store frequencies of all characters in string
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++) {
        freq[s[i]]++;
        
        if (freq[s[i]] > mxCnt) {
            mxCnt = freq[s[i]];
            ch = s[i];
        }
    }
    
    // Check if the result is possible or not
    if (mxCnt > ((n+1)/2))
        return "";
    
    // Filling the most frequently occurring char at
    // even indices
    int ind = 0;
    while (mxCnt > 0) {
        s[ind] = ch;
        ind = ind + 2;
        mxCnt--;
    }
    freq[ch] = 0;

    // Filling rest of the characters first at even positions, 
    // then odd positions.
    for (char ch = 'a'; ch <= 'z'; ch++) {

        while (freq[ch] > 0) {
            
            // Switch to odd, when all even positions were filled
            ind = (ind >= n) ? 1 : ind;
            s[ind] = ch;
            ind += 2;
            freq[ch]--;
        }
    }
    
    return s;
}

int main() {
    string s = "aaabc";
    cout << rearrangeString(s);
    return 0;
}
