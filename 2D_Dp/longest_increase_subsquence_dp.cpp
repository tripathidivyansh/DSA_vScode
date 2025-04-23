#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int curr, int prev, vector<vector<int>>&dp){
    if(curr == n){
        return 0;
    }
    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }
    int take = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        take = 1+solve(n, arr, curr+1, curr, dp);
    }
    int nottake = 0+solve(n, arr, curr+1, prev, dp);
    dp[curr][prev] = max(take, nottake);
    return dp[curr][prev+1];


}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    int ans = solve(n, arr, 0,  -1, dp);
    cout << ans;
}