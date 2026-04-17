#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    stack<int> ms;

    for(int i = 0; i < n; i++){

        while(!ms.empty() && arr[ms.top()] >= arr[i]){
            ms.pop();
        }

        if(ms.empty()){
            cout << 0 << ' ';
        }else{
            cout << ms.top() + 1 << ' ';
        }

        ms.push(i);
    }

}