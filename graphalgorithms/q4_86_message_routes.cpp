#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,curr;
    cin >> n >> m;

    vector<vector<int>> adjlist(n+1);
    vector<int> prevnode(n+1,-1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    prevnode[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr == n){
            vector<int> ans;
            ans.push_back(curr);
            while(prevnode[curr] != 0){
                ans.push_back(prevnode[curr]);
                curr = prevnode[curr];
            }
            reverse(ans.begin(),ans.end());
            cout << ans.size() << '\n';
            for(auto it:ans) cout << it << ' ';
            return 0;
        }
        for(int nb:adjlist[curr]){
            if(prevnode[nb] == -1){
                prevnode[nb] = curr;
                q.push(nb);
            }
        }
    }

    cout << "IMPOSSIBLE";
}