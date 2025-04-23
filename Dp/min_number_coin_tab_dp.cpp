#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& coin, int amount, vector<int>& dp) {
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coin.size(); j++) {
            if(i - coin[j] >= 0 && dp[i - coin[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coin[j]]);
            }
        }
    }
    if (dp[amount] == INT_MAX) {
        return -1;
    } else {
        return dp[amount];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> coin(n);
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int amount;
    cin >> amount;
    vector<int> dp(amount + 1, INT_MAX); 

    int ans = solve(coin, amount, dp);
    cout << ans << endl;
    
    return 0;
}
