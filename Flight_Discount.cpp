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

    vector<vector<int>> dist(n + 1, vector<int>(2, 1e18));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
    
    dist[1][0] = 0;  
    pq.push({0, {1, 0}});

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int node = top.second.first;
        int choice = top.second.second;

        if(d > dist[node][choice]) continue;

        for(auto &it : adj[node]) {
            int v = it.first;
            int w = it.second;


            if(d + w < dist[v][choice]) {
                dist[v][choice] = d + w;
                pq.push({dist[v][choice], {v, choice}});
            }

            if(choice == 0) {
                int ww = w / 2;
                if(d + ww < dist[v][1]) {
                    dist[v][1] = d + ww;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]);
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}