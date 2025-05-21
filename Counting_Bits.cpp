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

int count(int n) {
    if(n == 0) return 0;
    if(n < 2) return 1;
    int p = 1;
    int c = 0;
    while((p << 1) <= n) {
        p = p << 1;
        c++;
    }
    // cout << p << " " << c << endl;

    int ans = c * (p >> 1);
    int rem = n - p;
    ans += (rem + 1);
    return ans + count(rem);
}

void solve(){
    int n;
    cin >> n;
    // int ans = 0;
    // for(int i = 1; i < 63; i++) {
    //     int blockSize = (1LL << i);
    //     int blocks = n / blockSize;
    //     ans += ((blockSize/ 2) * blocks); // ek block me half 1s honge
    //     int rem = n % blockSize;
    //     ans += max(0LL, rem - (blockSize / 2) + 1);

    // }
    // cout << ans << endl;

    // Another solution

    cout << count(n);

}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}