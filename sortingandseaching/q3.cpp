#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int carr = 0;
    int l = 0;
    int r = n-1;
    while(l < r){
        if(arr[l]+arr[r] <= x){
            carr++;
            l++;
            r--;
        }else{
            carr++;
            r--;
        }
    }
    if(l == r) carr++;
    cout << carr << '\n';
}