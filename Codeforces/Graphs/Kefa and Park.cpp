#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define vbl vector<bool>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
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
#define N 100005

vbl visited(N,false);
vi adj[N];
vi cat(N);
ll m;

void dfs(ll s , ll d){
    if(visited[s] == true) return;

    if(cat[s] == 0) d = 0;
    else if(cat[s] == 1 && d + 1 <= m) d++;
    else return;

    visited[s] = true;

    for(auto u : adj[s]) dfs(u,d);
}

int main() {

    fast;

    ll n;
    cin in n in m;

    fo(i,1,n) cin in cat[i];

    fo(i,1,n-1){
        ll a,b;
        cin in a in b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1,0);

    ll ans = 0;
    fo(i,2,n) if(adj[i].size() == 1 && visited[i] == true) ans++;

    cout out ans;

    return 0;
}
