#include <bits/stdc++.h>
using namespace std;
void func23(int n, vector<pair<int,int>>&ans);
void func12(int n, vector<pair<int,int>>&ans);
void func32(int n, vector<pair<int,int>>&ans);
void func31(int n, vector<pair<int,int>>&ans);
void func21(int n, vector<pair<int,int>>&ans);
void func13(int n, vector<pair<int,int>>&ans){
    if(n == 1){
        ans.push_back({1,3});
        return;
    }
    func12(n-1,ans);
    ans.push_back({1,3});
    func23(n-1,ans);
}
void func23(int n, vector<pair<int,int>>&ans){
    if(n == 1){
        ans.push_back({2,3});
        return;
    }
    func21(n-1,ans);
    ans.push_back({2,3});
    func13(n-1,ans);
}
void func12(int n, vector<pair<int,int>>&ans){
    if(n == 1){
        ans.push_back({1,2});
        return;
    }
    func13(n-1,ans);
    ans.push_back({1,2});
    func32(n-1,ans);
}
void func32(int n, vector<pair<int,int>>&ans){
    if(n == 1){
        ans.push_back({3,2});
        return;
    }
    func31(n-1,ans);
    ans.push_back({3,2});
    func12(n-1,ans);
}
void func31(int n, vector<pair<int,int>>&ans){
    if(n == 1){
        ans.push_back({3,1});
        return;
    }
    func32(n-1,ans);
    ans.push_back({3,1});
    func21(n-1,ans);
}
void func21(int n, vector<pair<int,int>>&ans){
    if(n == 1){
        ans.push_back({2,1});
        return;
    }
    func23(n-1,ans);
    ans.push_back({2,1});
    func31(n-1,ans);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    func13(n,ans);
    cout << ans.size() << '\n';
    for(auto it:ans){
        cout << it.first << ' '<< it.second << '\n';
    }
}