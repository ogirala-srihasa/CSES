#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,a,b;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        if((a+b)%3 == 0){
            if(2*b >= a && 2*a >= b) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else cout << "NO" << '\n';
    }
}