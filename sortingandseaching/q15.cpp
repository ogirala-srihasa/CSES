#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> x >> n;
    set<int> path;
    multiset<int> len;
    path.insert(0);
    path.insert(x);
    len.insert(x);
    int c,r,l;
    for(int i = 0; i < n; i++){
        cin >> c;
        auto it = path.upper_bound(c);
        r = *it;
        it--;
        l = *it;
        path.insert(c);
        len.erase(len.find(r-l));
        len.insert(r-c);
        len.insert(c-l);
        it = len.end();
        it--;
        cout << *it << ' ';
    }

}