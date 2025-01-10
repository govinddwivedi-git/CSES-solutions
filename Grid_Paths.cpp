#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define pb push_back
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

vector<vector<int>> dp(1002,vector<int>(1002,-1));

int f(int i, int j, vector<vector<char>> &arr) {
    if(i<0 || j<0) return 0;
    if(arr[i][j] == '*') return 0;
    if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int left = f(i,j-1,arr) % mod;
    int up = f(i-1,j,arr) % mod;
    return dp[i][j] = (left + up) % mod;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> v[i][j];
            // cout << v[i][j];
        }
        // cout << endl;
    } 
    if(v[0][0] == '*' || v[n-1][n-1] == '*') {
        cout << 0;
        return;
    }
    cout << f(n-1,n-1,v);

    
}


int32_t main(){
    fast

    int t = 1;
    // cin >> t;
    while(t--){
        
        
        solve();


    }
    return 0;
}