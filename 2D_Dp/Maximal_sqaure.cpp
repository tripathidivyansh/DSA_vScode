#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mat, int i, int j, int& maxi) {
    if (i >= mat.size() || j >= mat[0].size()) {
        return 0;
    }

    int right = solve(mat, i, j + 1, maxi);
    int diagonal = solve(mat, i + 1, j + 1, maxi);
    int down = solve(mat, i + 1, j, maxi);

    if (mat[i][j] == 1) {
        int ans = 1 + min({right, diagonal, down});
        maxi = max(maxi, ans);
        return ans;
    } else {
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

    int maxi = 0;
    solve(mat, 0, 0, maxi);
    
    cout << maxi << endl;

    return 0;
}
