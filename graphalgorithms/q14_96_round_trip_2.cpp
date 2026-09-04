#include <bits/stdc++.h>
using namespace std;

bool detectandprintcycle(int i, vector<vector<int>>&adj, vector<bool>&vis, vector<int>&par, vector<bool>& pathvis){
    vis[i] = true;
    pathvis[i] = true;
    for(int nb:adj[i]){
        if(pathvis[nb]){
            vector<int> cycle;
            cycle.push_back(nb);
            int curr = i;
            while(curr != nb){
                cycle.push_back(curr);
                curr = par[curr];
            }
            cycle.push_back(nb);
            reverse(cycle.begin(),cycle.end());
            cout << cycle.size() << '\n';
            for(auto it:cycle) cout << it << ' ';
            return true;
        }
        if(!vis[nb]){
            par[nb] = i;
            if(detectandprintcycle(nb,adj,vis,par,pathvis)){
                return true;
            };
        }
    }

    pathvis[i] = false;
    return false;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    cin >> n >> m;

    vector<vector<int>> adjlist(n+1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
    }

    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,-1);
    vector<bool> pathvis(n+1,false);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(detectandprintcycle(i,adjlist,vis,parent,pathvis)) return 0;
        }
    }

    cout << "IMPOSSIBLE";

}