#include <bits/stdc++.h>
using namespace std;
long long func(int arr[],int i, long long cs, long long s, int n){
    if(i == n){
        return abs(2*cs-s);
    }
    long long p1 = func(arr,i+1,cs+arr[i],s,n);
    long long p2 = func(arr,i+1,cs,s,n);
    return min(p1,p2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    long long s = 0;
    for(int i = 0; i < n ;i++){
        cin >> arr[i];
        s += arr[i];
    }
    cout << func(arr,0,0,s,n) << '\n';

}