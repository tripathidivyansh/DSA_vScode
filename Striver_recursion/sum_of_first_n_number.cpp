#include<bits/stdc++.h>
using namespace std;

void solve(int i, int sum){
    if(i<1){
        // print(sum);
        cout << sum << " ";
        return;
    }
    solve(i-1, sum+i);

}
int main(){
    int n;
    cin >> n;

    solve(n,0);
}