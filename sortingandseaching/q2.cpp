#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> applicant(n);
    vector<int> apartment(m);
    for(int i = 0; i < n; i++){
        cin >> applicant[i];
    }
    for(int i = 0; i < m; i++){
        cin >> apartment[i];
    }
    sort(apartment.begin(),apartment.end());
    sort(applicant.begin(),applicant.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i < n && j < m){
        if(applicant[i]-k <= apartment[j] && apartment[j] <= applicant[i]+k){
            ans++;
            i++;
            j++;
        }else if(applicant[i]-k > apartment[j]){
            j++;
        }else{
            i++;
        }
    }
    cout << ans << '\n';
}