#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n,c;
    cin >> n >> m;
    multiset<int> tickets;
    
    for(int i= 0; i < n; i++){
        cin >> c;
        tickets.insert(c);
    }

    for(int i= 0; i<m; i++){
        cin >> c;
        auto it = tickets.lower_bound(c);
        if(tickets.empty()) cout << -1 << '\n';
        else if(it == tickets.end()){
            cout << *(--it) << '\n';
            tickets.erase(it);
        }
        else if(it == tickets.begin() && *tickets.begin() != c) cout << -1 << endl;
        else if(*it == c){
            cout << c << '\n';
            tickets.erase(it);
        }else{
            cout << *(--it) << '\n';
            tickets.erase(it);
        }
    }

}