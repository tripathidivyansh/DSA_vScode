#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& cost, int n){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
}
int main(){

    int n;
    cin >> n;
    vector<int>cost(n);
    for(int i = 0; i<n; i++){
        cin >> cost[i];
    }
    int ans = min(solve(cost, n-1), solve(cost, n-2));
    
    cout <<  ans << endl;
}                   