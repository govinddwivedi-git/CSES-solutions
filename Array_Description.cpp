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

int f(int ind, int prev, int m, vector<vector<int>> &dp, vector<int> &arr) {
    if(ind == 0) {
        if(arr[0] != 0) {
            if(abs(arr[0] - prev) <= 1) return 1;
            return 0;
        }
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            if(abs(prev - i) <= 1) {
                cnt++;
            }
        }
        return cnt;
    }
    if(arr[ind] != 0) {
        if(abs(arr[ind] - prev) > 1 && prev != 0) return 0;
        return dp[ind][prev] = f(ind-1, arr[ind], m, dp, arr);
    }

    if(dp[ind][prev] != -1) return dp[ind][prev];
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        if(abs(prev - i) <= 1) {
            cnt = (cnt + f(ind - 1, i, m, dp, arr)) % mod;
        }
    }

    dp[ind][prev] = cnt;
    return dp[ind][prev];


}

void solve(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(n == 1) {
        if(arr[0] != 0) {
            cout << 1 << endl;
            return;
        }
        cout << m << endl;
        return;
    }

    vector<vector<int>> dp(n, vector<int>(m+2, 0));
   
    if(arr[0] == 0){
        for (int j = 1; j <= m; j++){
            dp[0][j] = 1;
        }
    } 
    else {
        dp[0][arr[0]] = 1;
    }
     
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i] != 0 && arr[i] != j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
    }
     
    int ans = 0;
    for(int j = 1; j <= m; j++) {
        ans = (ans + dp[n-1][j]) % mod;
    }
    cout << ans << endl;
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}  