#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> pos(n+1);
    int curr;
    for(int i = 0; i < n; i++){
        cin >> curr;
        pos[curr] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(pos[i] > pos[i+1]){
            ans++;
        }
    }
    cout << ans << '\n';
}