#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long prev,c;
    long long ans;
    cin >> n;
    cin >> c;
    ans = c;
    prev = c;
    for(int i = 1; i < n; i++){
        cin >> c;
        prev = max(c,prev+c);
        ans = max(ans,prev);
    }
    cout << ans;
}