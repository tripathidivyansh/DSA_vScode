#include <bits/stdc++.h> 
using namespace std;

long long int solve(vector<int>& num) {
    int n = num.size();
    long long int prev2 = 0, prev1 = num[0];

    for(int i = 1; i < n; i++) {
        long long int include = prev2 + num[i];
        long long int exclude = prev1;

        long long int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) {
        return valueInHouse[0];  
    }
    vector<int> first, second;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            first.push_back(valueInHouse[i]);
        }
        if (i != 0) {
            second.push_back(valueInHouse[i]);  
        }
    }

    return max(solve(first), solve(second));  
}

int main() {
    int n;
    cin >> n;
    vector<int> valueInHouse(n);
    
    for (int i = 0; i < n; i++) {
        cin >> valueInHouse[i];
    }
    cout << houseRobber(valueInHouse) << endl;
    return 0;
}
