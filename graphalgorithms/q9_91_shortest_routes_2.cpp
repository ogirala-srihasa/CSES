#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q,a,b;
    long long c;
    cin >> n >> m >> q;

    vector<vector<long long>> mssp(n+1,vector<long long>(n+1, LLONG_MAX));
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        mssp[a][b] = min(mssp[a][b],c);
        mssp[b][a] = mssp[a][b];

    }

    for(int i = 1; i <= n; i++){
        mssp[i][i] = 0;
    }

    for(int via = 1; via <= n; via++){
        for(int source = 1; source <= n; source++){
            for(int dest = 1; dest <= n; dest++){
                if(mssp[source][via] == LLONG_MAX || mssp[via][dest] == LLONG_MAX || source == dest || via == source || via == dest) continue;
                mssp[source][dest] = min(mssp[source][dest], mssp[source][via] + mssp[via][dest]);
            }
        }
    }
        
    

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        (mssp[a][b] == LLONG_MAX) ? cout << -1 << '\n' : cout << mssp[a][b] << '\n';
    }


}