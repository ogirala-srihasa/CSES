#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    //int arr[n];
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    set<int> ans;
    ans.insert(0);
    for(int i = 0; i < n; i++){
        vector<int> ext;
        for(auto it: ans){
            ext.push_back(it + arr[i]);
        }
        for(auto it:ext) ans.insert(it);
    }

    ans.erase(0);
    cout << ans.size() << '\n';
    for(int it: ans){
        cout << it << ' ';
    }
}