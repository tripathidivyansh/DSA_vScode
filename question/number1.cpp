#include<bits/stdc++.h>
using namespace std;
void ans(int n){
    if(n==0){
        return;
    }
    ans(n-1);
    cout << n << " ";
}
int main(){
    int n;
    cin >> n;
    ans(n);
}