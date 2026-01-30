#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> hm(26);
    int mc = 0;
    for(auto it:s){
        hm[it-'A']++;
        mc = max(mc,hm[it-'A']);
    }
    int n = s.size();
    if(mc > (n+1)/2){
        cout << -1 << '\n';
        return 0;
    }
    char maxc,sc;
    bool flag;
    char prev = ' ';
    string ans = "";
    for(int i = 0; i < n; i++){
        mc = 0;
        flag = true;
        for(int j = 0; j < 26; j++){
            if(flag && hm[j] > 0 && ('A'+j) != prev){
                flag = false;
                sc = 'A'+j;
                //cout << j << sc << '\n';
            }
            if(hm[j] > mc && ('A'+j) != prev){
                mc = hm[j];
                maxc = 'A' +j;
            }
        }
        if(2*mc == (n-i+1)){
            ans += maxc;
            hm[maxc-'A']--;
            prev = maxc;
        }else{
            ans += sc;
            hm[sc-'A']--;
            prev = sc;
        }
    }
    cout << ans << '\n';
}