#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> ds, int arr[], int n, int target, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(ds);
        return;
    }
    if (index >= n || target < 0) {
        return;
    }

    ds.push_back(arr[index]);
    solve(index + 1, ds, arr, n, target - arr[index], result);
    ds.pop_back();

    while (index + 1 < n && arr[index] == arr[index + 1]) {
        index++;
    }

    solve(index + 1, ds, arr, n, target, result);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    sort(arr, arr + n); 

    vector<vector<int>> result;
    vector<int> ds;
    solve(0, ds, arr, n, target, result);

    for (auto subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
