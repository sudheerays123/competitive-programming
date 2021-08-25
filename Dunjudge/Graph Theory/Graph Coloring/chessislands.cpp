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
#define N 50005

vector<bool> visited(N,false);
vi color(N,INF);
vi adj[N];
ll area0 , area1;
vi area(N);

void dfs(ll s , ll c){

    if(visited[s]) return;
    visited[s] = true;

    color[s] = c;

    if(c == 0) area0 += area[s];
    else area1 += area[s];

    for(auto u : adj[s]){
        if(color[u] == INF){
            dfs(u,c == 1 ? 0 : 1);
        }
    }
}

int main() {

    fast;

    ll n,m;
    cin in n in m;

    fo(i,1,n) cin in area[i];

    fo(i,1,m){
        ll a,b;
        cin in a in b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll ans = 0;

    fo(i,1,n){
        if(visited[i]) continue;

        area0 = 0 , area1 = 0;
        dfs(i,1);

        ans += min(area0,area1);
    }

    cout out ans;

    return 0;
}
