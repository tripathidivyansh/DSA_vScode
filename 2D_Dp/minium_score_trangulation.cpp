#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int i, int j) {
    if (i + 1 == j) {
        return 0;
    }

    int ans = INT_MAX; 
    for (int k = i + 1; k < j; k++) {
        ans = min(ans, arr[i] * arr[j] * arr[k] + solve(arr, i, k) + solve(arr, k, j));
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = solve(arr, 0, n - 1);
    cout << result << endl;

    return 0;
}
