#include <bits/stdc++.h>
using namespace std;

// Global visited array is faster than passing vector
bool vis[7][7];
string inp;

// Check if a coordinate is valid and not visited
bool isValid(int r, int c) {
    return r >= 0 && r < 7 && c >= 0 && c < 7 && !vis[r][c];
}

long long func(int i, int r, int c) {
    // 1. Base Case: Reached step 48
    if (i == 48) {
        return (r == 6 && c == 0); // Standard CSES ends at (6,0)
    }

    // 2. Early Exit: Reached goal too early
    if (r == 6 && c == 0) return 0;

    // 3. OPTIMIZATION: Wall Splitting
    // If we hit a wall/path vertically but horizontal moves are open -> Dead End
    if (!isValid(r+1, c) && !isValid(r-1, c) && 
         isValid(r, c-1) && isValid(r, c+1)) return 0;

    // If we hit a wall/path horizontally but vertical moves are open -> Dead End
    if (!isValid(r, c+1) && !isValid(r, c-1) && 
         isValid(r+1, c) && isValid(r-1, c)) return 0;

    vis[r][c] = true;
    long long ans = 0;

    // 4. Recursive Calls
    // UP
    if (inp[i] == '?' || inp[i] == 'U') {
        if (r > 0 && !vis[r-1][c]) ans += func(i + 1, r - 1, c);
    }
    // DOWN
    if (inp[i] == '?' || inp[i] == 'D') {
        if (r < 6 && !vis[r+1][c]) ans += func(i + 1, r + 1, c);
    }
    // LEFT
    if (inp[i] == '?' || inp[i] == 'L') {
        if (c > 0 && !vis[r][c-1]) ans += func(i + 1, r, c - 1);
    }
    // RIGHT (Fixed typo here, was 'D' in your code)
    if (inp[i] == '?' || inp[i] == 'R') {
        if (c < 6 && !vis[r][c+1]) ans += func(i + 1, r, c + 1);
    }

    vis[r][c] = false; // Backtrack
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> inp;
    
    // Reset visited array
    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++) vis[i][j] = false;
        
    cout << func(0, 0, 0) << endl;
}