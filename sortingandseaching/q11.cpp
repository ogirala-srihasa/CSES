#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int nxt = 1;
    int ans = 1;
    while(true){
        for(int i = 0; i < n; i++){
            if(arr[i] == nxt){
                arr[i] = -1;
                nxt++;
            }
        }
        if(nxt == n+1) break;
        else ans++;
    }
    cout << ans;
}