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


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> cuts(k);
    for(int &i : cuts) cin >> i;
    set<int> st;
    multiset<int> mt;

    st.insert(0);
    st.insert(n);
    mt.insert(n);

    for(int i = 0; i < k; i++) {
        int c = cuts[i];
        auto it = st.upper_bound(c);
        int right = *it;
        int left = *prev(it);

        // debug2(left, right);

        int diff = right - left;
        mt.erase(mt.find(diff));

        int part1 = c - left;
        int part2 = right - c;
        mt.insert(part1);
        mt.insert(part2);
        st.insert(c);

        cout << *mt.rbegin() << " ";
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