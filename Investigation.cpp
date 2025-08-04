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
    int n, m; 
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n + 1, 1e18);
    vector<int> count(n + 1, 0);
    vector<int> minEdge(n + 1, 1e18);    
    vector<int> maxEdge(n + 1, -1e18);    


    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    count[1] = 1;
    minEdge[1] = 0;
    maxEdge[1] = 0; 

    while(!pq.empty()) {
        pii p = pq.top();
        pq.pop();

        int d = p.first;
        int node = p.second;

        if(d > dist[node]) continue;

        for(auto &i : adj[node]) {
            int v = i.first, wt = i.second;
            if(d + wt < dist[v]) {
                dist[v] = d + wt;
                count[v] = count[node];
                pq.push({dist[v], v});
                minEdge[v] = minEdge[node] + 1;
                maxEdge[v] = maxEdge[node] + 1;

            }
            else if(d + wt == dist[v]) {
                count[v] = (count[v] + count[node]) % mod;
                minEdge[v] = min(minEdge[v], minEdge[node] + 1);
                maxEdge[v] = max(maxEdge[v], maxEdge[node] + 1);
            }
        }
    }

    cout << dist[n] << " " << count[n] << " " << minEdge[n] << " " << maxEdge[n];
    
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}