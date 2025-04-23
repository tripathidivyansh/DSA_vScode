#include<bits/stdc++.h>
using namespace std;

int ans(int n){
    if(n < 10){
        return 1;

    }
    int count = 0;
    while(n > 0){
        n /= 10;
        count++;
    }
    return count;
}
int main(){
    int n;
    cin >> n;

    int result = ans(n);
    cout << result;
    return 0;
}