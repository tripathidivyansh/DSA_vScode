#include<bits/stdc++.h>
using namespace std;

bool ans(int n, int temp, int original){
    if(n==0){
        return temp == original;
    }
    temp = temp * 10 + n%10;
    return ans(n/10, temp, original);
}
int main(){
    int n;
    cin >> n;

    if(ans(n,0,n)){
        cout << "yes";
    }else{
        cout << "No";
    }
}