#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& days, vector<int>& cost, int index) {
    // Base Case
    if (index >= n) {
        return 0;
    }

    // 1-day pass
    int option1 = cost[0] + solve(n, days, cost, index + 1);

    // 7-day pass
    int i = index;  
    while (i < n && days[i] < days[index] + 7) i++;
    int option2 = cost[1] + solve(n, days, cost, i);

    // 30-day pass
    i = index;
    while (i < n && days[i] < days[index] + 30) i++;
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

int main() {
    int n;
    cin >> n;

    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    vector<int> cost(3);  
    for (int i = 0; i < 3; i++) {
        cin >> cost[i];
    }

    int ans = solve(n, days, cost, 0);
    cout << ans;
    
    return 0;
}
