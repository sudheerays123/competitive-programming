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

    ll n,sx,sy,tx,ty,t;
    cin in n in sx in sy in tx in ty in t;

    vector<vi> grid(n+5,vi(n+5,1));

    fo(i,1,t){
        ll x,y;
        cin in x in y;

        grid[x][y] = 0;
    }

    queue<pll> q;
    vector<vi> dist(n+5,vi(n+5,INF));

    q.push({sx,sy});
    dist[sx][sy] = 0;

    vi dx = {-2,-1,1,2,2,1,-1,-2};
    vi dy = {-1,-2,-2,-1,1,2,2,1};

    while(!q.empty()){
        ll a = q.front().first;
        ll b = q.front().second;
        q.pop();

        fo(t,0,7){
            ll aa = a+dx[t];
            ll bb = b+dy[t];

            if(aa >= 1 && aa <= n && bb >= 1 && bb <= n && grid[aa][bb] == 1 && dist[a][b] + 1 < dist[aa][bb]){
                dist[aa][bb] = dist[a][b] + 1;
                q.push({aa,bb});
            }
        }

    }

    if(dist[tx][ty] == INF) cout out "-1";
    else cout out dist[tx][ty];

    return 0;
}
