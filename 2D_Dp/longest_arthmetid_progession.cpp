#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int index, int& maxi){
    if(index>=n){
        return 0;
    }
    int maxlength = 1;
    for(int i = index+1; i<n; i++){
        int diff = arr[i]-arr[index];
        int length = 2;

        int prev = arr[i];
        for(int j = i+1; j<n; j++){
            if(arr[j] - prev == diff){
                length++;
                prev = arr[j];
            }
        }
        maxi = max(maxi, length);
    }
    return maxi;
}
int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int maxi = 0;

    int ans = solve(n, arr, 0, maxi);
    cout << ans;
    return 0;
}