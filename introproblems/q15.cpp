#include <bits/stdc++.h>
using namespace std;
void func(string curr,int arr[], set<string>&st,int n){
    if(curr.size() == n){
        st.insert(curr);
        return;
    }
    for(char i = 'a'; i <= 'z'; i++){
        if(arr[i-'a']){
            arr[i-'a']--;
            func(curr+i,arr,st,n);
            arr[i-'a']++;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string inp;
    cin >> inp;
    int n = inp.size();
    int arr[26] = {0};
    for(int i = 0; i < n; i++){
        arr[inp[i]-'a']++;
    }
    set<string> st;
    func("",arr,st,n);
    cout << st.size() << '\n';
    for(auto it:st){
        cout << it << '\n';
    }

}