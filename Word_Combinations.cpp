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


// int f(string &s, set<string> &st, int ind, vector<int> &dp) {
//     int n = s.size();
//     if(ind == n) return 1;
//     if(dp[ind] != -1) return dp[ind];

//     string temp = "";
//     int cnt = 0;
//     for(int i = ind; i < n; i++) {
//         temp += s[i];
//         if(st.find(temp) != st.end()) {
//             cnt = (cnt + f(s, st, i + 1, dp)) % mod;
//         }
//     }

//     return dp[ind] = cnt;
// }


void solve(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    set<string> st;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        st.insert(t);
    }

    vector<int> dp(s.size(), 0);
    int m = s.size();
    dp[m] = 1;
    for(int ind = m - 1; ind >= 0; ind--) {
        string temp = "";
        int cnt = 0;
        for(int i = ind; i < m; i++) {
            temp += s[i];
            if(st.find(temp) != st.end()) {
                cnt = (cnt + dp[i + 1]) % mod;
            }
        }

        dp[ind] = cnt;
    }
    int ans = dp[0];
    cout << ans;
    
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}