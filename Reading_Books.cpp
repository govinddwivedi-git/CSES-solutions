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


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];


    sort(all(a));
    vector<int> b = a;
    reverse(all(b));


    
    7 6 4
    6 7 

    int i = 0, j = 0;
    int sum1 = 0; 
    int sum2 = 0;
    while(i < n && j < n) {
        if(sum1 + a[i] <= sum2 + b[j]) {
            sum1 += a[i++];
        }
        else sum2 += b[j++];
    }

    while(i < n ) {
         
        sum1 += a[i++];
        
    }
    while(j < n ) {
       
        sum2 += b[j++];
        
    }

    cout << sum1 + sum2 << endl;
    
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