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

vector<int> dp(1000005, -1);

int f(int n) {
    if(n==0) return 0;
    int ans = INT_MAX;
    if(dp[n] != -1) return dp[n];
    int temp = n;
    vec v;
    while(n) {
        int d = n%10;
        if(d) v.pb(d);
        n/=10;
    }
    for(auto x: v) {
        ans = min(ans, 1+f(temp-x));
    }
    return dp[temp] = ans;
}

vector<int> getDigits(int n) {
    vector<int> digits;
    while(n){
        int d = n % 10;
        n /= 10;
        if(d) digits.push_back(d);
    }

    return digits;
}

void solve(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    for(int i = 1; i <= min(n, 9ll); i++) {
        dp[i] = 1;
    }
    for(int i = 10; i <= n; i++) {
        vector<int> dig = getDigits(i);
        for(auto d : dig) {
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }

    cout << dp[n];
    // cout << f(n) << endl;
    
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