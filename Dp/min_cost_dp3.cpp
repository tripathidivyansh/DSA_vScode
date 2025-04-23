#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&cost, int n){
    vector<int>dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i<n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]); 
}
int main(){
    int n;
    cin >> n;

    vector<int>cost(n);
    for(int i = 0; i<n; i++){
        cin >> cost[i];
    }
    int ans = solve(cost, n);
    cout << ans;
    return 0;
}