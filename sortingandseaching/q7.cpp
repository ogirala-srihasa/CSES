#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    map<int,int> hm;
    vector<int> arr(n);
    bool found = false;
    vector<int> ans(2);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(hm.find(x-arr[i]) != hm.end()){
            found = true;
            ans[0] = hm[x-arr[i]];
            ans[1] = i;
            break;
        }else{
            hm[arr[i]] = i;
        }
    }
    if(found){
        cout << ans[0]+1 << ' ' <<  ans[1]+1;
    }else{
        cout << "IMPOSSIBLE";
    }
}