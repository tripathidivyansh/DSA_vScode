#include <bits/stdc++.h>
using namespace std;

int solve(int index, int arr[], int n, int target, vector<vector<int>>& dp) {
    if (target == 0) return 1;
    if (index >= n || target < 0) return 0;
    
    if (dp[index][target] != -1) return dp[index][target];

    bool include = solve(index + 1, arr, n, target - arr[index], dp);
    bool exclude = solve(index + 1, arr, n, target, dp);

    return dp[index][target] = (include || exclude);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalsum = accumulate(arr, arr + n, 0);

    if (totalsum % 2 != 0) {
        cout << 0;
        return 0;
    }

    int target = totalsum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    int ans = solve(0, arr, n, target, dp);
    cout << ans;

    return 0;
}
