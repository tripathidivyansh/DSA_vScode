#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;


int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return ((a%MOD) * 1LL *(b%MOD))%MOD;
}

int solve(int n, int k, vector<int>&dp){

    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k, k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = add(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1)); 
    return dp[n];
}
int main(){
    int n;
    cin >> n;

    int k;
    cin >> k;
    vector<int>dp(n+1, -1);
    int ans = solve(n, k, dp);
    cout << ans;
    return 0;
}