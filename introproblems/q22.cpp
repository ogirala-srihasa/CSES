#include <bits/stdc++.h>
using namespace std;
void func(long long c){
    long long size = 1;
    long long curr = 9;
    while(true){
        if(c <= size*curr){
            break;
        }else{
            c -= size*curr;
            size++;
            curr*= 10;
        }
    }
    long long num = (curr/9) + ((c-1)/size);
    long long digit = (c-1)%size;
    curr = curr/9;
    long long i = 0;
    while(curr > 0){
        if(i == digit){
            cout << num/curr << '\n';
            break;
        }else{
            num = num%curr;
            curr = curr/10;
            i++;
        }
    }



}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    long long c;
    for(int i = 0; i < t; i++){
        cin >> c;
        func(c);
    }

}