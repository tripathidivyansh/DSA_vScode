// #include<bits/stdc++.h>
// using namespace std;
// int solve(vector<int>&num, int n){
//     if(n < 0){
//         return 0;
//     }
//     if(n==0){
//         return num[0];
//     }
    
//     int include = solve(num, n-2) + num[n];
//     int exclude = solve(num, n-1) + 0;

//     return max(include, exclude);
// }
// int main(){

//     int n;
//     cin >> n;

//     vector<int>num(n);
//     for(int i = 0; i<n; i++){
//         cin >> num[i];
//     }
//     int ans = solve(num, n-1);
//     cout << ans  << endl;
//     return ans;
// }

// taking the sum from the font side

#include<bits/stdc++.h>
using namespace std; 


int solve(vector<int>&num, int n){
    if(n>= num.size()){
        return 0;
    }
    int include = solve(num, n+2) + num[n];
    int exlude = solve(num, n+1);

    return max(include, exlude);
}
int main(){
    int n;
    cin >> n;

    vector<int> num(n);
    for(int i = 0; i<n; i++){
        cin >> num[i];
    }
    int ans = solve(num, 0);
    cout << ans;
    return 0;
}