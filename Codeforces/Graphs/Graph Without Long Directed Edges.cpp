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
#define N 200005

vector<bool> visited(N,false);
vi color(N,-1);
vi adj[N];
bool possible = true;

void dfs(ll s, ll p , ll c){
    if(visited[s] == true) return;
    visited[s] = true;

    color[s] = c;

    for(auto u : adj[s]) {
        if(u == p) continue;
        if(color[u] == color[s] || possible == false) {
            possible = false;
            return;
        }

        if(color[u] == -1) dfs(u,s,c == 1 ? 2 : 1);
    }
}

int main() {

    fast;

    ll n,m;
    cin in n in m;

    vector<pll> edge(m+5);

    fo(i,1,m){
        cin in edge[i].first in edge[i].second;

        adj[edge[i].first].pb(edge[i].second);
        adj[edge[i].second].pb(edge[i].first);
    }

    dfs(1,0,1);

    if(possible == false){
        cout out "NO";
        return 0;
    }

    cout out "YES\n";

    fo(i,1,m){
        if(color[edge[i].first] == 1) cout out "1";
        else cout out "0";
    }

    return 0;
}
