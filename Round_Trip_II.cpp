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

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &cycle) {
    vis[node] = 1;
    pathVis[node] = 1;
    cycle.push_back(node);
    for(auto &it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, node, adj, vis, pathVis, cycle)) return true;
        }
        else if(pathVis[it]) {
            cycle.push_back(it);
            return true;
        }
    }
    pathVis[node] = 0;
    cycle.pop_back();
    return false;
}


void solve(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n + 1);
    vector<int> pathVis(n + 1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vector<int> cycle;
            if(dfs(i, -1, adj, vis, pathVis, cycle)) {
                int element = cycle.back();
                int ind = -1;
                for(int i = 0; i < cycle.size(); i++) {
                    if(element == cycle[i]) {
                        ind = i;
                        break;
                    }
                }
                cout << cycle.size() - ind << endl;
                for(int i = ind; i < cycle.size(); i++) {
                    cout << cycle[i] << " ";
                }
                return;
            }
        }
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