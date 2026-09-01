#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int n;
vector<long long> tree; // Fenwick tree, 1-indexed
int m;                  // number of distinct compressed values

void update(int pos, long long val) {
    for (; pos <= m; pos += pos & (-pos))
        tree[pos] = (tree[pos] + val) % MOD;
}

long long query(int pos) {
    long long s = 0;
    for (; pos > 0; pos -= pos & (-pos))
        s = (s + tree[pos]) % MOD;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    // Coordinate compression
    vector<long long> sorted_vals = x;
    sort(sorted_vals.begin(), sorted_vals.end());
    sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());
    m = sorted_vals.size();

    tree.assign(m + 1, 0);

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        // rank = 1-indexed position of x[i] in sorted_vals
        int r = int(lower_bound(sorted_vals.begin(), sorted_vals.end(), x[i]) - sorted_vals.begin()) + 1;

        long long less_sum = query(r - 1);
        long long dp_i = (1 + less_sum) % MOD;

        update(r, dp_i);
        answer = (answer + dp_i) % MOD;
    }

    cout << answer << "\n";
    return 0;
}