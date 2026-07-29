#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >>m;
    vector<int> arr1(n), arr2(m);
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int j = 0; j < m; j++){
        cin >> arr2[j];
    }

    vector<vector<int>> prev(m+1,vector<int>(0));
    vector<vector<int>> curr(m+1,vector<int>(0));

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(arr1[i] == arr2[j-1]){
                curr[j] = prev[j-1];
                curr[j].push_back(arr1[i]);
            }else{
                int o1 = prev[j].size();
                int o2 = curr[j-1].size();
                int o3 = prev[j-1].size();
                int bo = max({o1,o2,o3});

                if(bo == o1) curr[j] = prev[j];
                else if(bo == o2) curr[j]= curr[j-1];
                else curr[j] = prev[j-1];
            }
        }

        prev = curr;
    }

    cout << prev[m].size() << '\n';
    for(auto it:prev[m]) cout << it << ' ';

}