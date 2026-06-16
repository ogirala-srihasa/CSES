#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    int n,x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for(int i = 0; i < n; i++){
        cin >> price[i];
    }

    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<int> prev(x+1,0);
    vector<int> curr(x+1,0);
    prev[0] = 0;
    curr[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(price[i] > j){
                curr[j] = prev[j];
            }else{
                curr[j] = max(prev[j], pages[i]+ prev[j-price[i]]);
            }
        }

        prev = curr;
    }

    cout << curr[x];
}