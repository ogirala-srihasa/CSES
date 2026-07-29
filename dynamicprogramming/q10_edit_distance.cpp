#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<int> ahead(m+1,1);
    vector<int> curr(m+1,-1);
    for(int i = 0; i <= m; i++){
        ahead[i] = m - i;
    }
    for(int i = n-1; i >= 0;  i--){
        curr[m] = n - i;
        for(int j = m-1; j >= 0; j--){
            if(s1[i] == s2[j]) curr[j] = ahead[j+1];
            else{
                curr[j] = 1 + min({ahead[j+1],ahead[j],curr[j+1]});
            }
        }

        ahead = curr;
    }

    cout << ahead[0];
}