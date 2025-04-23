#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int curr, int prev){
    if(curr==n){
        return 0;
    }
    // include
    int take = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        take = 1 + solve(n, arr, curr+1, curr);
    }

    int nottake = 0+solve(n, arr, curr+1, prev);
    return max(take, nottake);

}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int ans = solve(n, arr, 0, -1);
    cout << ans;
}