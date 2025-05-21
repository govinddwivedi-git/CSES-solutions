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
    string s;
    cin >> s;
    map<char,int> mp;
    for(auto &ch : s) {
        mp[ch]++;
    }
    int odd = 0;
    int sum = 0;

    for(auto &it : mp) {
        if(it.second & 1) {
            odd++;
        }
        sum += it.second;
    }

    if(odd > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    int pos = sum / 2;
    string ans = "";
    char oddchar = '!';
    for(auto &it : mp) {
        if(it.second & 1) {
            it.second--;
            oddchar = it.first;
        }
    }

    for(auto &it : mp) {
        ans += string(it.second/2, it.first);
        it.second /= 2;
    }

    if(oddchar != '!') ans += oddchar;

    for(auto it = mp.rbegin(); it != mp.rend(); it++) {
        ans += string(it->second, it->first);
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