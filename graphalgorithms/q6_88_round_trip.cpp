#include <bits/stdc++.h>
using namespace std;

bool detectandprintcycle(int i, vector<vector<int>>&adj, vector<bool>&vis, vector<int>&par){
    par[i] = 0;
    vis[i] = true;
    queue<int> q;
    q.push(i);
    int curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        for(int nb:adj[curr]){
            if(vis[nb] && par[curr] != nb){
                vector<int> parentscurr;
                vector<int> parentsnb;
                while(curr != 0){
                    parentscurr.push_back(curr);
                    curr = par[curr];
                }
                while(nb != 0){
                    parentsnb.push_back(nb);
                    nb = par[nb];
                }
                reverse(parentsnb.begin(),parentsnb.end());
                int ii = 0;
                int jj = parentscurr.size() -1;
                while (parentscurr[jj] == parentsnb[ii])
                {
                    ii++;
                    jj--;
                }
                jj++;
                ii--;
                vector<int> cycle;
                for(int k = 0; k < jj; k++){
                    cycle.push_back(parentscurr[k]);
                }
                for(int k = ii; k < parentsnb.size(); k++){
                    cycle.push_back(parentsnb[k]);
                }
                cycle.push_back(parentscurr[0]);
                cout << cycle.size() << '\n';
                for(int it:cycle) cout << it << ' ';
                return true;
            }else if(!vis[nb]){
                vis[nb] =true;
                par[nb] = curr;
                q.push(nb);
            }
        }
    }

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
        adjlist[b].push_back(a);
    }

    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,-1);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(detectandprintcycle(i,adjlist,vis,parent)) return 0;
        }
    }

    cout << "IMPOSSIBLE";

}