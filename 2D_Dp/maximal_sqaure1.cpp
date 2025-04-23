#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mat, int i, int j, int& maxi, vector<vector<int>>& dp) {
    if (i >= mat.size() || j >= mat[0].size()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int right = solve(mat, i, j + 1, maxi, dp);
    int diagonal = solve(mat, i + 1, j + 1, maxi, dp);
    int down = solve(mat, i + 1, j, maxi, dp);

    if (mat[i][j] == 1) {
        dp[i][j] = 1 + min({right, diagonal, down});
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    } else {
        dp[i][j] = 0;
        return 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = 0;
    solve(mat, 0, 0, maxi, dp);
    
    cout << maxi << endl;

    return 0;
}
