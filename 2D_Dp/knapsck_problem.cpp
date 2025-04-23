#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&weight, vector<int>&value, int index, int capacity, vector<vector<int>>&dp){

    if(index==0){
        if(weight[0] <= capacity){
            return value[0];
        }else{
            return 0;
        }
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(weight, value, index-1, capacity-weight[index], dp);
    }
    int exclude = solve(weight, value, index-1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
int main(){
    int n;
    cin >> n;

    vector<int>weight(n);
    for(int i = 0; i<n; i++){
        cin >> weight[i];
    }
    vector<int>value(n);
    for(int i =0; i<n; i++){
        cin >> value[i];
    }            
    int maxWeight;
    cin >> maxWeight;
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    int ans = solve(weight, value, n - 1, maxWeight, dp);

    cout << ans;
}  