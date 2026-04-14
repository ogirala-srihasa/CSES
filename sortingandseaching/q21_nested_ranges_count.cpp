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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Range> arr(n);
  for(int i = 0; i < n; i++){
    arr[i].index = i;
    cin >> arr[i].start >> arr[i].end;
  }
  vector<int> ans1(n);
  vector<int> ans2(n);
  sort(arr.begin(), arr.end());

  int max_end = INT_MIN;
  int min_end = INT_MAX;
  for(int i = 0; i < n; i++){
    if(arr[i].end <= max_end){
      ans1[arr[i].index] = 1;
    }else max_end = arr[i].end;
    if(arr[n-i-1].end >= min_end) ans2[arr[n-i-1].index] = 1;
    else min_end = arr[n-i-1].end;
  }

  for(int i = 0; i < n; i++){
    cout << ans2[i] << ' ';
  }
  cout << '\n';
  for(int i = 0; i < n; i++){
    cout << ans1[i] << ' ';
  }

}