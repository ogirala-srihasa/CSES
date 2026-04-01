// Given n ranges, your task is to determine for each range if it contains some
// other range and if some other range contains it. Range [a,b] contains range
// [c,d] if a \le c and d \le b.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> arr(n, vector<int>(2));
  vector<vector<int>> arr_copy(n, vector<int>(2));
  vector<int> ans1(n);
  vector<int> ans2(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
    arr_copy[i][0] = arr[i][0];
    arr_copy[i][1] = arr[i][1];
  }

  sort(arr_copy.begin(), arr_copy.end());
}