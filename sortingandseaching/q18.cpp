#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> hm;
    for(int i = 1; i <= n; i++){
        hm.insert(i);
    }
    auto it = hm.begin();
    while(hm.size()){
        if(it == hm.end()) {
            it = hm.begin();
            continue;
        }
        if(it == --hm.end()){
            cout << *hm.begin() << ' ';
            hm.erase(hm.begin());
            it = hm.begin();
        }else{
            it++;
            auto c = it;
            it++;
            cout << *c << ' ';
            hm.erase(c);
        }

    }
}