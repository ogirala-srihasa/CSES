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

    sort(arr.begin(),arr.end());
    long long target = 1;
    for(long long i:arr){
        if(i > target) break;
        else target += i;
    }

    cout << target;
}