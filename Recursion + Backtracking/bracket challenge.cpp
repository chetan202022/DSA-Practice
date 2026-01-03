
// https://www.hackerrank.com/contests/gl-bajaj-self-evaluation-evening-batch/challenges/bracket-challenge-1/problem

#include<bits/stdc++.h>
using namespace std;
set<string> ans;
stack<char> stk;
void makeBP(int open_n , int close_n , int open_m , int close_m , string& s){
    if(open_n == 0 && close_n == 0 && open_m == 0 && close_m == 0){
        ans.insert(s);
        return ;
    }
    if(open_n){
        s += '(';
        stk.push('(');
        makeBP(open_n - 1 , close_n , open_m , close_m , s);
        stk.pop();
        s.pop_back();
    }
    if(close_n > open_n && !stk.empty() && stk.top() == '('){
        char c = stk.top();
        stk.pop();
        s += ')';
        makeBP(open_n, close_n - 1, open_m , close_m , s);
        s.pop_back();      
        stk.push(c);
    }
    if(open_m){
        s += '{';
        stk.push('{');
        makeBP(open_n, close_n , open_m - 1, close_m , s);
        stk.pop();
        s.pop_back();
    }
    if(close_m > open_m && !stk.empty() && stk.top() == '{'){
        char c = stk.top();
        stk.pop();
        s += '}';
        makeBP(open_n, close_n, open_m , close_m -1, s);
        s.pop_back();   
        stk.push(c);
    }
}

int main()
{
    int n , m ;
    cin>>n>>m;
    string s = "";
    makeBP(n , n  , m , m , s);
    for(auto it : ans){
        cout<<it<<endl;
    }
}
