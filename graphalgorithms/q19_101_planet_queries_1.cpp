#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> jump(n+1,vector<int>(32,0));
    for(int i = 1; i <= n; i++){
        cin >> jump[i][0];
    }

    for(int i = 1; i < 32; i++){
        for(int planet = 1; planet <= n; planet++){
            jump[planet][i] = jump[jump[planet][i-1]][i-1];
        }
    }

    int start,q;
    for(int i = 0; i < m; i++){
        cin >> start >> q;
        for(int bit = 0; bit < 32; bit++){
            if(q & 1 << bit){
                start = jump[start][bit];
            }
        }

        cout << start << '\n';
    }



}