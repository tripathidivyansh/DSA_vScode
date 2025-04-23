#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> &ds, int sum, int target, int arr[], int n) {
    if (index == n) {
        if (sum == target) {  
            for (int i = 0; i < ds.size(); i++) {
                cout << ds[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    solve(index + 1, ds, sum, target, arr, n);

    sum -= arr[index];
    ds.pop_back();
    solve(index + 1, ds, sum, target, arr, n);
}

int main() {
    int n;
    cout << "Enter the input: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum;
    cout << "Enter the sum of the number: ";
    cin >> sum;

    vector<int> ds;
    solve(0, ds, 0, sum, arr, n);

    return 0;  
}
