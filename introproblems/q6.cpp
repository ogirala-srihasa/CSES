#include <bits/stdc++.h>
using namespace std;
long long f(long long x){
    long long x2 = x*x;
    return x2-x+1;
}
long long func(int x, int y){
    if(x == y) return f(x);
    if(x < y){
        long long yy = f(y);
        if(y%2 == 1) return yy + x - y;
        else return yy - x + y;
    }else{
        long long xx = f(x);
        if(x%2 == 0) return xx + y -x;
        else return xx -y+x;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int x,y;
    for(int i = 0; i < t; i++){
        cin >> x >> y;
        cout << func(y,x) << '\n';
    }
}