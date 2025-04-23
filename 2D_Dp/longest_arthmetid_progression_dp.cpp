#include <bits/stdc++.h>
using namespace std;

int solve(int index, int diff, vector<int>& arr, unordered_map<int, int> dp[]) {
    if (index < 0) {
        return 0;
    }
    if (dp[index].count(diff)) {
        return dp[index][diff];
    }

    int ans = 0;

    for (int j = index - 1; j >= 0; j--) {
        if (arr[index] - arr[j] == diff) {
            ans = max(ans, 1 + solve(j, diff, arr, dp));
        }
    }
    return dp[index][diff] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    unordered_map<int, int> dp[n + 1];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, 2 + solve(i, arr[j] - arr[i], arr, dp));
        }
    }   

    cout << ans;
    return 0;
}
