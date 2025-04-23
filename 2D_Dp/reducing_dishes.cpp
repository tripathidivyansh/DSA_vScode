#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int index, int time, int n){
    if(index ==  n){
        return 0;
    }

    int include = arr[index] * (time+1) + solve(arr, index+1, time+1, n);

    int exclude =  0 + solve(arr, index + 1, time, n);

    return max(include, exclude);
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    } 
    sort(arr, arr+n);
    int ans = solve(arr, 0, 0, n);
    cout << ans;
    return 0;
}