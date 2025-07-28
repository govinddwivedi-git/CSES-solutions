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
const char dirs[4] = {'D', 'R', 'U', 'L'};
const int N=2e5+5;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    
    queue<pair<int,int>> q;

    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<int>> monsterTime(n, vector<int>(m, 1e9));

    pair<int,int> start;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'A') {
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    cout << "YES" << endl;
                    cout << 0 << endl;
                    return;
                }
                start.first = i;
                start.second = j;
            }

            if(v[i][j] == 'M') {
                q.push({i, j});
                monsterTime[i][j] = 0;
            }
        }
    }


    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        int x = front.first, y = front.second;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && monsterTime[nx][ny] > 1 + monsterTime[x][y]) {
                monsterTime[nx][ny] = 1 + monsterTime[x][y];
                q.push({nx, ny});
            }
        }
    }

    queue<pair<int,int>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    pq.push(start);
    dist[start.first][start.second] = 0;
    while(!pq.empty()) {
        auto front = pq.front();
        pq.pop();
        int x = front.first, y = front.second;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.' && monsterTime[nx][ny] > 1 + dist[x][y] && dist[nx][ny] == 1e9) {
                dist[nx][ny] = 1 + dist[x][y];
                pq.push({nx, ny});
                parent[nx][ny] = {x, y};
                if(nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) {
                    string path = "";
                    pair<int, int> curr = {nx, ny};
                    while(curr != start) {
                        pair<int, int> prev = parent[curr.first][curr.second];
                        for(int k = 0; k < 4; k++) {
                            int row = prev.first + dx[k];
                            int col = prev.second + dy[k];
                            if(row == curr.first && col == curr.second) {
                                path += dirs[k];
                                break;
                            }
                        }
                        curr = prev;
                    }
                    reverse(all(path));
                    cout << "YES" << "\n" << path.size() << "\n" << path;
                    return;
                }

            }
        } 
    }

    cout << "NO";
    
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}