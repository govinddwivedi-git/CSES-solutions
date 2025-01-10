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
    int sum = n*(n+1)/2;
    if((sum)&1) {
        cout << "NO" << endl;
        return;
    }

    int x = sum / 2;

    vec even,odd;
    for(int i=1;i<=n;i+=2) odd.pb(i);
    for(int i=2;i<=n;i+=2) even.pb(i);

    int oddSum = accumulate(all(odd),0LL);
    int evenSum = accumulate(all(even),0LL);

    if(oddSum < evenSum) {
        swap(odd,even);
    }
    

    int diff = abs(oddSum - x);

    int cnt = 0;
    int i = odd.size()-1;
    while(cnt < diff) {
        odd[i--] -= 1;
        cnt++;
    }
    cnt = 0;
     i = even.size()-1;
    while(cnt < diff) {
        even[i--] += 1;
        cnt++;
    }

    cout << "YES" << endl;
    cout << odd.size() << endl;
    for(int i=0;i<odd.size();i++){
        cout << odd[i] << " ";
    }
    cout << endl;
    cout << even.size() << endl;
    for(int i=0;i<even.size();i++){
        cout << even[i] << " ";
    }
    

    // 1 3 5 7
    // 2 4 6
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}