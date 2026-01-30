#include  <bits/stdc++.h>
using namespace std;
void func(long long n){
    cout << n << " ";
    if(n == 1) return;
    if(n%2 == 0) func(n/2);
    else func(3*n+1);
}
int main(){
    long long l;
    cin >> l;
    func(l);
}