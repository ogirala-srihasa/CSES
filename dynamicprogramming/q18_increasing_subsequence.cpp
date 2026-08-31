#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        auto lb = lower_bound(lis.begin(),lis.end(),arr[i]);
        int lbi = lb - lis.begin();
        if(lbi == lis.size()) lis.push_back(arr[i]);
        else lis[lbi] = arr[i];
    }

    cout << lis.size();

}