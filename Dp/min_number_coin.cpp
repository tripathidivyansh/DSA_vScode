#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&coin, int amount){
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return INT_MAX - 1;
    }
    int mini = INT_MAX;
    for(int i = 0; i<coin.size(); i++){
        int ans = solve(coin , amount - coin[i]);

        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
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
    int ans = solve(coin, amount);

    if(ans == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}