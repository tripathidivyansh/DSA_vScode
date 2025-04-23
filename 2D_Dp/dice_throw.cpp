#include <bits/stdc++.h>
using namespace std;

int solve(int dice, int faces, int target) {
    if (target < 0) {
        return 0;
    }
    if (dice == 0) {
        if (target == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= faces; i++) {
        ans += solve(dice - 1, faces, target - i);
    }
    return ans;
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    int ans = solve(n, m, x);
    cout << ans;
    return 0;
}
