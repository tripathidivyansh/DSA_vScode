#include <bits/stdc++.h>
using namespace std;

void solve(int index, int arr[], int n, vector<vector<int>>& ans) {
    if (index == n) {
        ans.push_back(vector<int>(arr, arr + n)); 
        return;
    }
    for (int i = index; i < n; i++) {
        swap(arr[index], arr[i]);
        solve(index + 1, arr, n, ans);
        swap(arr[index], arr[i]); 
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> ans; 
    solve(0, arr, n, ans);

    for (auto& malik : ans) {
        for (int arr1 : malik) {
            cout << arr1 << " ";
        }
        cout << endl;
    }

    return 0;
}
