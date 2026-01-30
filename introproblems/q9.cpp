#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;

long long func(long long n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(n%2 == 0){
        long long a = func(n/2);
        return (a*a)%mod;
    }else{
        return (2 * func(n-1))%mod;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    cout << func(n);
}