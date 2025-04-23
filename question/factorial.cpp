#include<bits/stdc++.h>
using namespace std;

int  ans(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*ans(n-1);
}
int main(){
    int n;
    cin >> n;

    int res = ans(n);
    cout <<res << " ";
    return 0;
}