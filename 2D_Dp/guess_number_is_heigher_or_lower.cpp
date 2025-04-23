#include <bits/stdc++.h>
using namespace std;

int solve(int start, int end, vector<int> &arr, vector<vector<int>> &dp) {
    if (start >= end) {
        return 0;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }
    int maxi = INT_MAX;

    for (int i = start; i <= end; i++) {
        maxi = min(maxi, i + max(solve(start, i - 1, arr, dp), solve(i + 1, end, arr, dp)));
    }
    dp[start][end] = maxi;
    return dp[start][end];
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key; 
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solve(1, n, arr, dp);
    cout << ans << endl;
    return 0;
}
