#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long a = (n*(n+1))/2;
    if(a%2 == 1) cout << "NO";
    else{
        vector<int> arr1;
        vector<int> arr2;
        if(n%2 == 0){
            int i = 1;
            while(i <= n/2){
                if(i%2 == 1){
                    arr1.push_back(i);
                    arr1.push_back(n-i+1);
                }else{
                    arr2.push_back(i);
                    arr2.push_back(n-i+1);
                }
                i++;
            }
        }else{
            arr1.push_back(1);
            arr1.push_back(2);
            arr2.push_back(3);
            int l = 4;
            int r = n;
            while(l < r){
                if(l%2 == 0){
                    arr1.push_back(l);
                    arr1.push_back(r);
                }
                else{
                    arr2.push_back(l);
                    arr2.push_back(r);
                }
                l++;
                r--;
            }
        }
        cout << "YES" << '\n';
        cout << arr1.size() << '\n';
        for(int i = 0; i < arr1.size(); i++) cout << arr1[i] << ' ';
        cout << '\n' << arr2.size() << '\n';
        for(int i = 0; i < arr2.size(); i++) cout << arr2[i] << ' ';

    }
}