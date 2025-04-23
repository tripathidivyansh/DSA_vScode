// recursion
// coding ninza

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int solve(int n, int i){
    if(i == n){
        return 1;
    }
    if(i > n){
        return 0;
    }
    return (solve(n, i + 1) + solve(n, i + 2)) % MOD;
}
int main(){
    int n;
    cin >> n;

    int ans = solve(n, 0);
    cout << ans;
}