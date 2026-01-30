#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n < 4){
        cout << "NO SOLUTION";
        return 0;
    }
    for(int i = 1; i <= n/2; i++){
        cout << 2*i << ' ';
    }
    for(int i = 0; i < (n+1)/2; i++){
        cout << 2*i +1 << ' ';
    }
}