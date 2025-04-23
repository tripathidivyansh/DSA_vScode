#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n==0){
        return 0;
    }
    int ans = n;
    for(int i = 1; i*i<=n; i++){
        int temp = i*i;
        ans = min(ans, 1+solve(n-temp));

    }
    return ans;
}
int main(){
    int n;
    cin >> n;

    int ans = solve(n);
    cout << ans;
}