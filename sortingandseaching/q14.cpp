#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<int> arr;
    int c;
    for(int i = 0; i < n; i++){
        cin >> c;
        auto it = arr.upper_bound(c);
        if(it == arr.end()){
            arr.insert(c);
        }else{
            arr.erase(it);
            arr.insert(c);
        }
    }
    cout << arr.size();
}