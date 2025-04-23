#include<bits/stdc++.h>
using namespace std;

int solve( vector<int>& arr, int n, int target, vector<int>&dp){
    if(target < 0){
        return -1;
    }
    if(target == 0){
        return 0;
    }
    if(dp[target] != -1){
        return dp[target];
    }
    dp[target] = 0;
    for(int i = 0; i<n; i++){
        int res = solve(arr, n, target-arr[i], dp);

        if(res != -1){
            dp[target] += res;
        }
    }
    return dp[target];
}

int main(){
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<int>dp(n+1, -1);
    int ans = solve(arr, n, target, dp);
    cout << ans << " ";

    return 0;
}