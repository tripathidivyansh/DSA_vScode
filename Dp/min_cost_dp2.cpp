#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& cost, int n, vector<int>& dp) {
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<int> dp(n + 1, -1);

    int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));

    cout << ans << endl;
    return 0;
}
