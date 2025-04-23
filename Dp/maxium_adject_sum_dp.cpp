#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&num, int n, vector<int>&dp){
    if(n>=num.size()){
        return 0;
    }  
    if(dp[n] != -1){
        return dp[n];
    }
    int include = solve(num, n+2 ,dp) + num[n];
    int exclude = solve(num, n+1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}
int main(){
    int n;
    cin >> n;

    vector<int> num(n);
    for(int i = 0; i<n; i++){
        cin >> num[i];
    }
    vector<int>dp(n, -1);

    int ans = solve(num, 0, dp);
    cout << ans;
    return 0;
}