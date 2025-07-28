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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n + 1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(adj, i, vis, st);
        }
    }
    
    vector<vector<int>> adj2(n + 1);
    vector<int> vis2(n + 1);

    for(int i = 1; i <= n ; i++) {
        for(auto &it : adj[i]) {
            adj2[it].push_back(i);
        }
    }
    

    vector<int> kingdom(n + 1);
    int c = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis2[node]) {
            vector<int> comp;
            dfs2(adj2, node, vis2, comp);
            c++;
            for(auto &it : comp) {
                kingdom[it] = c;
            }
        }
    }

    cout << c << endl;
    for(int i = 1; i <=n; i++) {
        cout << kingdom[i] << " ";
    }


    





    
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}