#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>&dp){
    if(n<=1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
    for(int i =1;i<=n; i++){
        ans += solve(i-1, dp)*solve(n-i, dp);
    }
    dp[n] = ans;
    return dp[n];
    
}
int main(){
    int n;
    cin >> n;

    vector<int>dp(n+1, -1);
    int res = solve(n, dp);
    cout << res;
    return 0;
}