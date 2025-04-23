#include<bits/stdc++.h>
using namespace std;

// int solve(int n){
//     if(n<=0){
//         return 0;
//     }
//     cout << n << " ";
//     return solve(n-1);
// }

void solve(int n){
    if(n<=0){
        return;
    }
    cout << n<< " ";
    solve(n-1);
}
int main(){
    int n;
    cin >> n;

    // int ans  = solve(n);
    solve(n);
    return 0;
}