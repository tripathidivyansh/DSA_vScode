#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i + 1 == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++) {
        ans = min(ans, arr[i] * arr[j] * arr[k] + solve(arr, i, k, dp) + solve(arr, k, j, dp));
    }
    
    dp[i][j] = ans;
    return dp[i][j];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int res = solve(arr, 0, n - 1, dp);
    cout << res << endl;

    return 0;
}
