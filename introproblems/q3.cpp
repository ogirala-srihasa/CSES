#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int c = 1;
    int ans = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]) c++;
        else{
            ans = max(c,ans);
            c = 1;
        }
    }
    cout << max(ans,c);
}
