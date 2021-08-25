#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105

int main() {

    fast;

    ll n,m;
    cin in n in m;

    vector<vi> grid(n+5,vi(m+5));

    fo(i,1,n){
        fo(j,1,m){
            cin in grid[i][j];
        }
    }

    queue<pll> q;
    ll ans = 0;
    vector<vector<bool>> eaten(n+5,vector<bool>(m+5,false));

    q.push({1,1});
    ans += grid[1][1];
    eaten[1][1] = true;

    vi dx = {-1,1,0,0};
    vi dy = {0,0,-1,1};

    while(!q.empty()){
        ll a = q.front().first;
        ll b = q.front().second;
        q.pop();

        if(a == n && b == m) break;
        
        ll fmax = -INF , x,y;

        fo(t,0,3){
            ll aa = a+dx[t];
            ll bb = b+dy[t];

            if(aa >= 1 && aa <= n && bb >= 1 && bb <= m && grid[aa][bb] > fmax && eaten[aa][bb] == false){
                fmax = grid[aa][bb];
                x = aa;
                y = bb;
            }
        }

        q.push({x,y});
        eaten[x][y] = true;
        ans += grid[x][y];
    }

    cout out ans;

    return 0;
}
