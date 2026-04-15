#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2,0));
    vector<vector<int>> dep(n, vector<int>(2,0));
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> dep[i][0];
        arr[i][1] = i;
        dep[i][1] = i;
    }
    int rooms = 0;
    map<int,set<int>> hm;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    vector<int> roomnumber(n);
    set<int> f;
    set<int> o;
    hm[0] = f;
    hm[1] = o;
    int i = 0;
    int j = 0;
    while(i < n){
        if(arr[i][0] <= dep[j][0]){
            if(hm[0].size() == 0){
                rooms++;
                hm[1].insert(rooms);
                roomnumber[arr[i][1]] = rooms;
            }else{
                int c = *(hm[0].begin());
                hm[0].erase(c);
                hm[1].insert(c);
                roomnumber[arr[i][1]] = c;
            }
            i++;
        }else{
            int rn = roomnumber[dep[j][1]];
            hm[1].erase(rn);
            hm[0].insert(rn);
            j++;
        }
    }

    cout << rooms << '\n';
    for(int it:roomnumber) cout << it << ' ';

}