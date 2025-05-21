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
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int parent[n+1];
    vector<int> vis(n+1, 0);

    int start = 1;
    int end = n;

    queue<pair<int,int>> q;

    q.emplace(start,0);
    vis[start] = 1;
    parent[start] = start;

    while(!q.empty()) {
        auto f = q.front();
        int node = f.first;
        int step = f.second;
        q.pop();

        for(auto &it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.emplace(it,step+1);
                parent[it] = node;
            }

            if(it == end) {
                cout << step + 2 << endl;
                vector<int> ans;
                int current = end;
                ans.push_back(current);
                while(parent[current] != current){
                    current = parent[current];
                    ans.push_back(current);
                }
                reverse(all(ans));

                for(auto &i : ans) cout << i << ' ';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}