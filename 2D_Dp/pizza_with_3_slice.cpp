#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int endIndex, vector<int>& slices, int n) {
        if (n == 0 || index > endIndex) {
            return 0;
        }
        int take = slices[index] + solve(index + 2, endIndex, slices, n - 1);
        int notake = solve(index + 1, endIndex, slices, n);
        return max(take, notake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(0, k - 2, slices, k / 3);
        int case2 = solve(1, k - 1, slices, k / 3);
        return max(case1, case2);
    }
};

int main() {
    int n;
    cout << "Enter the number of slices: ";
    cin >> n;
    
    vector<int> slices(n);
    cout << "Enter the slice values: ";
    for (int i = 0; i < n; i++) {
        cin >> slices[i];
    }

    Solution sol;
    int result = sol.maxSizeSlices(slices);
    cout << "Maximum sum of selected slices: " << result << endl;

    return 0;
}
