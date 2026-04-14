#include <bits/stdc++.h>
using namespace std;

class Segmenttree{
    private:
    vector<int> tree;
    public:

    Segmenttree(int n){
        vector<int> t(4 * n);
        tree = t;
        buildtree(1,1,n);
    }

    void buildtree(int i, int left_bound, int right_bound){
        if(left_bound == right_bound) tree[i] = 1;
        else{
            int mid = left_bound+ (right_bound - left_bound)/2;
            buildtree(2*i,left_bound,mid);
            buildtree(2*i + 1, mid+1,right_bound);
            tree[i] = tree[2*i] + tree[2*i + 1];
        }
    }

    int remove(int i, int left_bound, int right_bound, int k){
        if(left_bound == right_bound){
            tree[i] = 0;
            return left_bound;
        }else{
            int ans;
            int mid = left_bound+ (right_bound - left_bound)/2;
            if(tree[2*i] >= k){
                ans = remove(2*i, left_bound,mid, k);
            }else{
                ans = remove(2*i +1, mid+1,right_bound, k - tree[2*i]);
            }
            tree[i] = tree[2*i] + tree[2*i + 1];
            return ans ;
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    Segmenttree t = Segmenttree(n);
    int pos = 0;
    for(int i = 0; i < n; i++){
        pos = (pos + k) % (n-i);
        cout << t.remove(1,1,n,pos+1) << ' ';
    } 

}