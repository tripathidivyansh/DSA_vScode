#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n<=1){
        return n;
    }
    int last = solve(n-1);
    int slast = solve(n-2);

    return last + slast;
}
int main(){
    int n;
    cin >> n;

    int ans = solve(n);
    cout << ans;
}