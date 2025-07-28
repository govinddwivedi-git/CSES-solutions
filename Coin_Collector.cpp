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


void dfs(vector<vector<int>> &adj, int node, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for(auto &it : adj[node]) {
        if(!vis[it]) dfs(adj, it, vis, st);
    }
    st.push(node);
}

void dfs2(vector<vector<int>> &adj, int node, vector<int> &vis, vector<int> &comp) {
    vis[node] = 1;
    comp.push_back(node);
    for(auto &it : adj[node]) {
        if(!vis[it]) dfs2(adj, it, vis, comp);
    }
}



void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++) cin >> coins[i];   
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    // Step 1: Kosaraju DFS for order
    stack<int> st;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(adj, i, vis, st);
    
    // Step 2: Reverse Graph
    vector<vector<int>> adj2(n + 1);
    for (int i = 1; i <= n; i++) for (auto &v : adj[i]) adj2[v].pb(i);

    // Step 3: Find SCCs
    vector<int> vis2(n + 1, 0), ids(n + 1);
    unordered_map<int, int> compCoins;
    int c = 0;
    
    while(!st.empty()) {
        int node = st.top(); st.pop();
        if(!vis2[node]) {
            vector<int> comp;
            dfs2(adj2, node, vis2, comp);
            c++;
            int sum = 0;
            for (int u : comp) {
                ids[u] = c;
                sum += coins[u];   // 2. Sum coins of SCC
            }
            compCoins[c] = sum;
        }
    }

    // Step 4: Build DAG of SCCs
    vector<vector<int>> dag(c + 1);
    vector<int> indeg(c + 1, 0);
    
    for(int u = 1; u <= n; u++) {
        for(auto v : adj[u]) {
            if (ids[u] != ids[v]) {
                dag[ids[u]].pb(ids[v]);
                indeg[ids[v]]++;
            }
        }
    }

    // Step 5: DP on DAG (Topological Order)
    vector<int> dp(c + 1, 0);
    queue<int> q;
    for(int i = 1; i <= c; i++) {
        dp[i] = compCoins[i];
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : dag[u]) {
            if(dp[v] < dp[u] + compCoins[v])
                dp[v] = dp[u] + compCoins[v];
            if(--indeg[v] == 0) q.push(v);
        }
    }

    // Step 6: Answer
    cout << *max_element(all(dp)) << endl;
}

int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}