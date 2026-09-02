#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int> par;
    vector<int> s;
    DisjointSet(int n){
        vector<int> parent(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
        vector<int> siz(n+1,1);
        par = parent;
        s = siz;
    }

    int findParent(int u){
        if(par[u] == u) return u;
        return par[u] = findParent(par[u]);
    }

    void connect(int u, int v){
        int paru = findParent(u);
        int parv = findParent(v);
        if(paru == parv) return;
        if(s[paru] > s[parv]) par[parv] = paru;
        else if(s[paru] == s[parv]){
            s[parv]++;
            par[paru] = parv;
        }else par[paru] = parv;
    }



};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    DisjointSet ds = DisjointSet(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        ds.connect(a,b);
    }

    int comp = 0;
    vector<int> fp;
    for(int i = 1; i <= n ; i++){
        if(ds.findParent(i) == i){
            comp++;
            fp.push_back(i);
        }
    }

    cout << fp.size()-1 << '\n';
    for(int i = 1; i < fp.size(); i++){
        cout << fp[i-1] << ' ' << fp[i] << '\n';
    }

}