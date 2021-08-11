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

vector<bool> visited(N,false);
vector<pll> adj[N];

void dfs(ll s , ll color){

    if(visited[s] == true) return;
    visited[s] = true;

    for(auto u : adj[s]) if(u.second == color) dfs(u.first,color);
}

int main() {

    fast;

    ll n,m;
    cin in n in m;

    unordered_set<ll> colors;

    fo(i,1,m){
        ll a,b,c;
        cin in a in b in c;

        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
        colors.insert(c);
    }

    ll q;
    cin in q;

    while(q--){

        ll u,v;
        cin in u in v;

        ll c = 0;

        for(auto color : colors){
            visited.clear();
            visited.resize(n+5,false);

            dfs(u,color);
            if(visited[v] == true) c++;
        }

        cout out c nextline;
    }

    return 0;
}
