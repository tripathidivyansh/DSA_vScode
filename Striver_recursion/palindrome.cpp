#include<bits/stdc++.h>
using namespace std;

bool solve(int i, string& s){
    int n = s.size();
    if(i>=n/2){
        return true;
    }
    if(s[i] != s[n-i-1]){
        return false;
    }
    return solve(i+1, s);
}
int main(){
    string s;
    cin >> s;

    solve(0, s);

    int ans = solve(0, s);
    cout << ans;
}