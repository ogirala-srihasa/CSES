#include <bits/stdc++.h>
using namespace std;
long long func(long long n, long long p,int m){
    if(p > n) return 0;
    return (n/p) + func(n,p*m,m);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    cout << func(n,5,5);
}