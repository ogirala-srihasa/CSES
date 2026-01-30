#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dep(n);
    for(int i= 0; i < n; i++){
        cin >> arr[i] >> dep[i];
    }
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i = 0;
    int j = 0;
    int cnt = 0;
    int ans = 0;
    while(i < n){
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
}