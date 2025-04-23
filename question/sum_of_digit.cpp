#include<bits/stdc++.h>
using namespace std;

int ans(int n){
    if(n<10){
        return n;
    }
    int sum = 0;
    while(n>0){
        sum += n%10;
        n /=10;
    }
    return ans(sum);

}
int main(){
    int n;
    cin >> n;

    int res = ans(n);
    cout << res;
    return 0;
}