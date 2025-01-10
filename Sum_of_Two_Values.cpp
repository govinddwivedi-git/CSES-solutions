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
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;
 
    vec arr(n);
    rep(i,n) cin >> arr[i];
 
    unordered_map<int,int,custom_hash> mp;
   
    for(int i=0;i<n;i++) {
        int ele = x - arr[i];
        if(mp.find(ele) != mp.end()) {
            cout << i+1 << " " << mp[ele] + 1;
            return;
        }
        mp[arr[i]] = i;
    }
 
    cout << "IMPOSSIBLE";
 
}
 
 
int32_t main(){
    fast
 
    int t = 1;
    while(t--){
        
        
        solve();
 
 
    }
    return 0;
}