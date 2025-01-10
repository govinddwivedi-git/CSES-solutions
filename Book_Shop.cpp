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

// vector<vector<int>> dp(1005, vector<int>(100005,-1));

// int f(int ind, vec &price, vec &pages, int x) {
//     if(x == 0) return 0;
//     if(ind == 0) {
//         if(price[ind] <= x) return pages[ind];
//         return 0;
//     } 
//     if(dp[ind][x] != -1) return dp[ind][x];
//     int nt = f(ind-1, price, pages, x);
//     int t = 0;
//     if(price[ind] <= x) {
//         t = pages[ind] + f(ind-1,price,pages,x-price[ind]);
//     }

//     return dp[ind][x] = max(nt, t);
// }

// giving runtime error


void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vec price(n);
    vec pages(n);

    rep(i,n) cin >> price[i];
    rep(i,n) cin >> pages[i];

    // cout << f(n-1,price,pages,x);


    // vector<vec> dp(n,vector<int>(x+1)); runtime error
    vec prev(x+1);


    for(int j=0; j<=x; j++) {
        prev[j] = (j >= price[0]) ? pages[0] : 0;
    }
    
    for(int i=1;i<n;i++) {
        vec curr(x+1);
        for(int j=0;j<=x;j++) {
            int nt = prev[j];
            int t = 0;
            if(price[i] <= j) t = pages[i] + prev[j - price[i]];
            curr[j] = max(t, nt);
        }
        prev = curr;
    }

    cout << prev[x];


    // vector<int> dp(x + 1, 0);
    // for(int i = 0; i < n; i++){
    //     for(int cost = x; cost >= price[i]; cost--){
    //         dp[cost] = max(dp[cost], dp[cost - price[i]] + pages[i]);
    //     }
    // }
    // cout << dp[x];





}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}