#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&coin, int amount, vector<int>&dp){
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return INT_MAX;
    }
    if(dp[amount] != -1){
        return dp[amount];
    }
    int mini = INT_MAX;
    for(int i = 0; i<coin.size(); i++){
        int ans = solve(coin, amount-coin[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    dp[amount] = mini;
    return mini;
}
int main(){

    int n;
    cin >> n;

    vector<int>coin(n);
    for(int i = 0; i<n; i++){
        cin >> coin[i];
    }
    int amount;
    cin >> amount;

    vector<int>dp(amount + 1, -1);
    
    int ans = solve(coin, amount, dp);
    if(ans == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans;
    }
    return 0;
}