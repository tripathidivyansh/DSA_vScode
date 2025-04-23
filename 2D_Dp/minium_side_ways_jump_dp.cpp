#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n, int currlane, int currpos, vector<vector<int>>&dp){
    if(currpos == n){
        return 0;
    }
    if(dp[currlane][currpos] != -1){
        return dp[currlane][currpos];
    }
    if(arr[currpos+1] != currlane){
        return solve(arr, n , currlane, currpos+1, dp);
    }else{
        int ans = INT_MAX;
        for(int i = 1; i<=3; i++){
            if(currlane != i && arr[currpos] != i){
                ans = min(ans, 1+solve(arr, n, i, currpos, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos]; 
    }
    
}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>>dp(4, vector<int>(n, -1));

    int ans = solve(arr,2, 0, n, dp);
    cout << ans;
    return 0;
}