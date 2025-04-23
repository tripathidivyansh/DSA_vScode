#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int index, int time, int n, vector<vector<int>>&dp){
    if(index == n){
        return 0;
    }
    if(dp[index][time] != -1){
        return dp[index][time];
    }
    int include = arr[index] * (time+1) + solve(arr, index+1, time+1, n, dp);

    int exclude = 0 + solve(arr, index+1, time, n, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}
int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    int ans = solve(arr, 0, 0, n, dp);
    cout << ans;
    return 0;
}