#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin >> n >> a >> b;

    vector<int> arr(n);
    for(int i = 0; i <n; i++){
        cin >> arr[i];
    }

    long long cpfsum = 0;
    map<int,long long> pfsum;
    multiset<long long> active;
    int r,l;
    for(int i = 0; i < n; i++){
        cpfsum += arr[i];
        pfsum[i] = cpfsum;
    }
    r  =  -1;
    l  =  a-b-1;
    pfsum[-1] = 0;
    long long ans = LLONG_MIN;
    for(int i = a-1; i < n; i++){
        if(pfsum.find(l-1) != pfsum.end()){
            active.erase(active.find(pfsum[l-1]));
        }
        active.insert(pfsum[r]);
        ans = max(ans, pfsum[i] - *active.begin());
        r++;
        l++;
    }

    cout << ans;
}