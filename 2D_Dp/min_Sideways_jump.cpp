#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int currlane, int currpos, int n) {
    if (currpos == n) {
        return 0;
    }
    if (arr[currpos + 1] != currlane) {
        return solve(arr, currlane, currpos + 1, n);
    } else {
        int res = INT_MAX;
        for (int i = 1; i <= 3; i++) {
            if (currlane != i && arr[currpos] != i) {
                res = min(res, 1 + solve(arr, i, currpos, n));
            }
        }
        return res;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = solve(arr, 2, 0, n);
    cout << ans;
    
    return 0;
}
