#include <bits/stdc++.h>
using namespace std;

int solve(int n, int faces, int target, vector<vector<int>>& dp) {
    if (n == 0) {
        if (target == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[n][target] != -1) {
        return dp[n][target];
    }

    int ans = 0;
    for (int i = 1; i <= faces; i++) { 
        if (target - i >= 0) {  
            ans += solve(n - 1, faces, target - i, dp);
        }
    }

    dp[n][target] = ans;
    return dp[n][target];
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));

    int ans = solve(n, m, x, dp);

    cout << ans << endl;
    return 0;
}
