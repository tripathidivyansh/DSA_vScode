#include<bits/stdc++.h>
using namespace std;

string  ans(string s){
    if(s.size() <=0){
        return s;
    }
    return ans(s.substr(1)) + s[0];
}
int main(){
    string s;
    getline(cin, s);

    string result = ans(s);
    cout << result << endl;
    return 0;
}