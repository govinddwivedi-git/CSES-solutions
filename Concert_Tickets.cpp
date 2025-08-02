#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
#define pb push_back
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
    int n, m;
    cin >> n >> m;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    vector<int> peoples(m);
    for(int i = 0; i < m; i++) cin >> peoples[i];
    
    map<int,int> mp;
    for(auto &i : prices) {
        mp[i]++;
    }

    for(int i = 0; i < m; i++) {
        int element = peoples[i];
        auto it = mp.upper_bound(element);
        if(it == mp.begin()) {
            cout << -1 << endl;
            continue;
        }
        --it;
        int x = it->first;
        mp[x]--;
        cout << x << endl;
        if(mp[x] == 0) mp.erase(x);
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