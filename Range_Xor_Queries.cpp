#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mini(a, b, c) min(c, min(a, b))
#define mini2(a, b, c, d) min(d, min(c, min(a, b))) 
#define rrep(i,s,n) for(int i=n-1;i>=s;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define scin(str) getline(cin, str)

// Debugging Macros
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl

// Aliases and Types
using vec = vector<int>;
using pii=pair<int,int>;
using mapi=map<int,int>;
using si=set<int>;

const int mod = 1e9+7;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;

template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree, lazy;
    vector<T> arr;

    T merge(T a, T b) {
        return a ^ b;
    }

    void apply(int idx, int l, int r, T val) {
        tree[idx] += (r - l + 1) * val;
        lazy[idx] += val;
    }

    void pushDown(int idx, int l, int r) {
        if (lazy[idx] != 0) {
            int mid = (l + r) / 2;
            apply(2 * idx, l, mid, lazy[idx]);
            apply(2 * idx + 1, mid + 1, r, lazy[idx]);
            lazy[idx] = 0;
        }
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void updateRange(int idx, int l, int r, int ql, int qr, T val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(idx, l, r, val);
            return;
        }
        pushDown(idx, l, r);
        int mid = (l + r) / 2;
        updateRange(2 * idx, l, mid, ql, qr, val);
        updateRange(2 * idx + 1, mid + 1, r, ql, qr, val);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void updatePoint(int idx, int l, int r, int pos, T val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        pushDown(idx, l, r);
        int mid = (l + r) / 2;
        if (pos <= mid) updatePoint(2 * idx, l, mid, pos, val);
        else updatePoint(2 * idx + 1, mid + 1, r, pos, val);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    T query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        pushDown(idx, l, r);
        int mid = (l + r) / 2;
        T left = query(2 * idx, l, mid, ql, qr);
        T right = query(2 * idx + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }

public:
    SegmentTree(vector<T> &input) {
        arr = input;
        n = arr.size();
        tree.assign(4 * n, 1e9);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void updateRange(int l, int r, T val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    void updatePoint(int pos, T val) {
        updatePoint(1, 0, n - 1, pos, val);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    SegmentTree<int> sg(arr);

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int ans = sg.query(l, r);
        cout << ans << endl;
    }
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}