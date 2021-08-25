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

    ll n,m,x,y,t;
    cin in n in m in x in y in t;

    vector<vi> grid(n+5,vi(m+5,INF));

    fo(i,1,n){
        fo(j,1,m){
            cin in grid[i][j];
        }
    }

    queue<pll> q;
    vector<vi> selected(n+5,vi(m+5,0));

    q.push({x,y});
    selected[x][y] = 1;

    vi dx = {-1,1,0,0};
    vi dy = {0,0,-1,1};

    while(!q.empty()){
        ll a = q.front().first;
        ll b = q.front().second;
        q.pop();

        fo(u,0,3){
            ll aa = a+dx[u];
            ll bb = b+dy[u];

            if(aa >= 1 && aa <= n && bb >= 1 && bb <= m && abs(grid[aa][bb]-grid[x][y]) <= t && selected[aa][bb] == 0){
                selected[aa][bb] = 1;
                q.push({aa,bb});
            }
        }
    }

    fo(i,1,n){
        fo(j,1,m){
            cout out selected[i][j];
        }
        cout nextline;
    }
    return 0;
}
