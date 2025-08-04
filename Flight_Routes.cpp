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


void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pii>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<priority_queue<int>> dp(n + 1);

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 1});
    dp[1].push(0);

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int dist = p.first;
        int u = p.second;

        if(dp[u].size() == k && dist > dp[u].top()) continue;

        for(auto &it : adj[u]) {
            int v = it.first;
            int w = it.second;

            int newD = dist + w;

            if(dp[v].size() < k) {
                dp[v].push(newD);
                pq.push({newD, v});
            }

            else if(newD < dp[v].top()) {
                dp[v].pop();
                dp[v].push(newD);
                pq.push({newD, v});
            }
        }
    }

    vector<int> ans;
    while(!dp[n].empty()) {
        ans.push_back(dp[n].top());
        dp[n].pop();
    }

    sort(all(ans));

    for(int i = 0; i < k; i++) 
        cout << ans[i] << " ";
    
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}