#include<bits/stdc++.h>
using namespace std;

bool solve(int index, vector<int>&ds,int s, int sum, int arr[], int n){
    if(index == n){
        for(int i = 0; i<ds.size(); i++){
            cout << ds[i] << " ";
            return true;
        }
        // condition not statisfied
        return false;
    }
    ds.push_back((arr[index]));
    s += arr[index];

    if(solve(index+1, ds, s, sum, arr, n) == true){
        return true;
    }
    s-= arr[index];
    ds.pop_back();

    if(solve(index+1, ds, s, sum, arr, n) == true) return true;

    return false;
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

    vector<int>ds;
    int ans = solve(0, ds, 0, sum, arr, n);
    cout << ans;
}