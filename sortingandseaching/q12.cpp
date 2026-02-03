#include <bits/stdc++.h>
using namespace std;
int func(int a, int pos[], int ne, int n){
    int l = a-1;
    int r = a+1;
    int ans = 0;
    if(l == 0){
        if(r > n) return ans;
        if(pos[a] < pos[r] && ne > pos[r]) ans++;
        else if(pos[a] > pos[r] && ne < pos[r]) ans--;
    }else{
        if(r > n){
            if(pos[a] > pos[l] && ne < pos[l]) ans++;
            else if(pos[a] < pos[l] && ne > pos[l]) ans--;
        }else{
            if(pos[a] > pos[l] && ne < pos[l]) ans++;
            else if(pos[a] < pos[l] && ne > pos[l]) ans--;
            if(pos[a] < pos[r] && ne > pos[r]) ans++;
            else if(pos[a] > pos[r] && ne < pos[r]) ans--;
        }
    }
    return ans;
}
int func2(int a, int pos[], int n){
    int l = a-1;
    int r = a+2;
    int ans = 0;
    if(pos[a] < pos[a+1]) ans++;
    else ans--;
    if(l == 0){
        if(r > n) return ans;
        if(pos[a+1] < pos[r] && pos[a] > pos[r]) ans++;
        else if(pos[a+1] > pos[r] && pos[a] < pos[r]) ans--;
    }else{
        if(r > n){
            if(pos[a] > pos[l] && pos[a+1] < pos[l]) ans++;
            else if(pos[a] < pos[l] && pos[a+1] > pos[l]) ans--;
        }else{
            if(pos[a] > pos[l] && pos[a+1] < pos[l]) ans++;
            else if(pos[a] < pos[l] && pos[a+1] > pos[l]) ans--;
            if(pos[a+1] < pos[r] && pos[a] > pos[r]) ans++;
            else if(pos[a+1] > pos[r] && pos[a] < pos[r]) ans--;
        }
    }
    return ans;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int arr[n];
    int pos[n+1];
    int ans = 1;
    int a,b,vala,valb;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for(int i = 1; i < n; i++){
        if(pos[i] > pos[i+1]){
            ans++;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a == b){
            cout << ans << '\n';
            continue;
        }
        vala =  arr[a-1];
        valb = arr[b-1];
        swap(arr[a-1],arr[b-1]);
        if(abs(vala-valb) == 1){
            ans += func2(min(vala,valb),pos,n);
        }else{
            ans += func(vala,pos,b-1,n);
            ans += func(valb,pos,a-1,n);
        }
        cout << ans << '\n';
        pos[vala] = b-1;
        pos[valb] = a-1;
    }

}