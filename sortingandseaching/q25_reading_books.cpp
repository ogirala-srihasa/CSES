#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    long long int tk = 0;
    long long int tj = arr[n-1];
    
    for(int i = 0; i < n-1; i++){
        tk += arr[i];
    }
    
    if(tj > tk) cout << 2 * tj;
    else cout << tk +tj;
    

}