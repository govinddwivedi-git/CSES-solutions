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

void f1(vector<int> &arr, int cnt, int ind, int sum, unordered_map<int,int>  &leftSum) {
    if(ind >= cnt) {
        leftSum[sum]++;
        return;
    }
    sum += arr[ind];
    f1(arr, cnt, ind + 1, sum, leftSum);
    sum -= arr[ind];
    f1(arr, cnt, ind + 1, sum, leftSum);
}

void f2(vector<int> &arr, int cnt, int ind, int sum, unordered_map<int,int> &rightSum, int rem) {
    if(cnt >= rem) {
        rightSum[sum]++;
        return;
    }
    if (ind < 0) return;
    sum += arr[ind];
    f2(arr, cnt + 1, ind - 1, sum, rightSum, rem);
    sum -= arr[ind];
    f2(arr, cnt + 1, ind - 1, sum, rightSum, rem);
}

void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int cnt = n/2;
    int rem = n - cnt;
    unordered_map<int,int> leftSum;
    f1(arr, cnt, 0, 0, leftSum);
    unordered_map<int,int> rightSum;

    f2(arr, 0, n-1, 0, rightSum, rem);


    int ans = 0;
    for(auto &it : leftSum) {
        int target = x - it.first;
        if(rightSum.find(target) != rightSum.end()) {
            ans += rightSum[target] * it.second;
        }
    }

    cout << ans << endl;



}


int32_t main(){
    fast

    int t = 1;
    // cin >> t;
    while(t--){
        
        
        solve();


    }
    return 0;
}