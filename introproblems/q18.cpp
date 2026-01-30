#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,a,b;
    cin >> t;
    for(int j = 0; j< t; j++){
        cin >> n >> a >> b;
        if(a+b > n){
            cout << "NO" << '\n';
            continue;
        }
        else{
            int d = n -(a+b);
            vector<int> arr(n);
            vector<int> brr(n);
            for(int i = 0; i < n; i++){
                brr[i] = i+1;
                if(i >= n-d){
                    arr[i] = i+1;
                }
            }
            int p = n-d;
            if(p == 0){
                cout << "YES" << '\n';
                for(int i= 0; i < n; i++){
                    cout << i+1 <<' ';
                }
                cout << '\n';
                for(int i= 0; i < n; i++){
                    cout << i+1 <<' ';
                }
                cout << '\n';
            }else{
                if(a == 0 || b == 0){
                    cout << "NO" << '\n';
                }else{
                    for(int k = 0; k < p; k++){
                        arr[k] = ((p-a+k)%p)+1;
                    }
                    cout << "YES" << '\n';
                    for(int i= 0; i < n; i++){
                        cout << arr[i] <<' ';
                    }
                    cout << '\n';
                    for(int i= 0; i < n; i++){
                        cout << brr[i] <<' ';
                    }
                    cout << '\n';
                }
            }
        }
    }
}