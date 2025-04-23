#include<bits/stdc++.h>
using namespace std;

int ans(int n, int m){
    if(m==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    return n*ans(n,m-1);
}
int main(){

    int n;
    cin >> n;
    
    int m;
    cin >> m;


    int result = ans(n,m);
    cout << result;
    return 0;
}