#include<bits/stdc++.h>
using namespace std;

int solve(int index, int s, int sum, int arr[], int n){
    if(s>sum) return 0;                         
    if(index == n){
        if(s == sum){
            return 1;
        }
        return 0;
    }
    s += arr[index];

    int l = solve(index+1,  s, sum, arr, n);
    s-= arr[index];

    int r = solve(index+1,s, sum, arr, n);
    
    return l+r;
}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int sum;
    cin >> sum;

    int ans = solve(0,  0, sum, arr, n);
    cout << ans;

}