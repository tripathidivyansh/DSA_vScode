#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int solve(int n, vector<int>&dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1; 
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] =  (((n - 1)) * ((solve(n - 1, dp) + solve(n - 2, dp))));


    return dp[n];
    

}
int main(){
    int n;
    cin >> n;
    vector<int>dp(n+1, -1);
    int ans = solve(n, dp);

    cout << ans;
}