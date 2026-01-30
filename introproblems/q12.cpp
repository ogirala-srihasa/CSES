#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string inp;
    cin >> inp;
    int n = inp.size();
    string ans = "";
    string ans2 = "";
    int hm[26] = {0};
    for(int i = 0; i < n; i++){
        if(hm[inp[i]-'A'] == 0){
            hm[inp[i]-'A']++;
        }else{
            hm[inp[i]-'A']--;
            ans += (inp[i]);
            //ans2 = inp[i] + ans2;
        }
    }
    int f = 0;
    string b = "";
    for(int i = 0; i < 26;i++){
        if(hm[i] == 1){
            if(f == 1){
                cout << "NO SOLUTION";
                return 0;
            }else{
                f++;
                b += char('A' + i);
            }
        }
    }
    cout << ans << b;
    reverse(ans.begin(),ans.end());
    cout << ans;
}