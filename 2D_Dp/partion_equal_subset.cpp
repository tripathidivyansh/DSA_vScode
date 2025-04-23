#include<bits/stdc++.h>
using namespace std;

bool solve(int index, int arr[], int n, int target){
    if(index >= n){
        return 0;
    }
    if(target < 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }
    int include = solve(index+1, arr, n, target-arr[index]);

    int exclude = solve(index+1, arr, n, target-0);


    return include or exclude;
}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    bool found = true;
    int totalsum = 0;
    for(int i = 0; i<n; i++){
        totalsum += arr[i];
    }
    if(totalsum%2 != 0){
        return 0;
    }
    int target = totalsum/2;

    int ans = solve(0,  arr, n,target);
    cout << ans;
}