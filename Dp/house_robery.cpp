#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& num, int n, vector<int>& dp) {
    if (n >= num.size()) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int include = solve(num, n + 2, dp) + num[n];
    int exclude = solve(num, n + 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

int robC(vector<int>& num) {
    int n = num.size();
    if (n == 1) {
        return num[0];
    }
    vector<int> nums1(num.begin(), num.end() - 1);
    vector<int> dp1(n - 1, -1);
    int case1 = solve(nums1, 0, dp1);

    vector<int> nums2(num.begin() + 1, num.end());
    vector<int> dp2(n - 1, -1);
    int case2 = solve(nums2, 0, dp2);

    return max(case1, case2);
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int ans = robC(num);
     cout << ans << endl;
    return 0;
}
