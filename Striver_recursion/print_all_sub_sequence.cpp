#include<bits/stdc++.h>
using namespace std;

void solve(int index, vector<int>&ds, int arr[], int n){
    if(index == n){
        for(int i = 0; i<ds.size(); i++){
            cout << ds[i] << " ";
        }
        if(ds.size() == 0){
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take
    ds.push_back(arr[index]);
    solve(index+1, ds, arr, n); 
    ds.pop_back();
    // not take

    solve(index+1, ds, arr, n);

}
int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<int>ds;
    solve(0, ds, arr, n);
    return 0;
}