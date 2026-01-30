#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int prev = 0;
    int curr;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> curr;
        if(curr >= prev){ 
            //cout << prev << curr << '\n';
            prev = curr;}
        else{
            //cout << prev << curr << '\n';
            ans += prev - curr;
        }
    }
    cout << ans;
}