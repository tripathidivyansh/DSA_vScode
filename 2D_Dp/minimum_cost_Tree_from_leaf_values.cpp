#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], map<pair<int,int>,int>&maxi, int left, int right, vector<vector<int>>&dp){
    if(left == right){
        return 0;
    }
    if(dp[left][right] != -1){
        return dp[left][right];
    }
    int ans = INT_MAX;
    for(int i = left; i<right; i++){
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}]+ solve(arr, maxi, left, i, dp) + solve(arr, maxi, i+1, right, dp));
    }
    dp[left][right] = ans;
    return dp[left][right];
}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    map<pair<int,int>,int>maxi;
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    for(int i = 0; i<n; i++){
        maxi[{i,i}] = arr[i];

        for(int j = i+1; j<n; j++){
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }

    }
    int ReSult = solve(arr, maxi, 0, n-1, dp);
    cout << ReSult;
    return 0;
}