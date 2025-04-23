#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr, int n, int target){
    if(target < 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += solve(arr, n, target-arr[i]);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    int target;
    cin >> target;
    int ans = solve(arr, n, target);
    cout << ans;
}