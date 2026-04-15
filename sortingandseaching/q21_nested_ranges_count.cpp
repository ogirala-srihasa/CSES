#include <bits/stdc++.h>
using namespace std;

class Range{
  public:
  int start;
  int end;
  int index;

  Range(int start, int end, int index){
    this -> start = start;
    this -> end = end;
    this -> index = index;
  }

  Range(){
    this -> start = 0;
    this -> end = 0;
    this -> index = 0;
  }

  bool operator<(const Range&other) const{
    if(start < other.start) return true;
    else if(start == other.start) return end > other.end;
    return false;
  }
};
class Fenwicktree{
  public:
  vector<int> tree;
  int n;

  Fenwicktree(int n){
    vector<int> t(n+1,0);
    tree = t;
    this -> n = n;
  }

  void add(int i, int val){
    for(; i <= n; i += i & -i){
      tree[i] += val;
    }
  }

  int count(int i){
    int c = 0;
    for(; i > 0; i -= i & -i){
      c += tree[i];
    }
    return c;
  }

};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Range> arr(n);
  set<int> hm;
  map<int,int> rank;
  for(int i = 0; i < n; i++){
    arr[i].index = i;
    cin >> arr[i].start >> arr[i].end;
    hm.insert(arr[i].end);
  }
  vector<int> ans1(n);
  vector<int> ans2(n);
  sort(arr.begin(), arr.end());
  int c = 1;
  for(auto it: hm){
    rank[it] = c;
    c++;
  }
  Fenwicktree f1(hm.size());
  Fenwicktree f2(hm.size());
  for(int i = 0; i < n; i++){
    ans1[arr[i].index] = f1.count(c-1) - f1.count(rank[arr[i].end] -1);
    f1.add(rank[arr[i].end],1);
    ans2[arr[n-i-1].index] = f2.count(rank[arr[n-i-1].end]);
    f2.add(rank[arr[n-i-1].end],1);
    
  }

  for(int i = 0; i < n; i++){
    cout << ans2[i] << ' ';
  }
  cout << '\n';
  for(int i = 0; i < n; i++){
    cout << ans1[i] << ' ';
  }

}