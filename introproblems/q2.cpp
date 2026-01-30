#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long as = (n*(n+1))/2;
    long long c;
    for(int i = 0; i < n-1; i++){
        cin >> c;
        as -= c;
    }
    cout << as << "\n";

}