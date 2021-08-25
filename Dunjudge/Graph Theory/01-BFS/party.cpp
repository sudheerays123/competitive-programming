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

    vi adj[n+5];

    fo(i,1,m){
        ll a,b;
        cin in a in b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<ll> q;
    vi dist(n+5,INF);

    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        ll a = q.front();
        q.pop();

        for(auto u : adj[a]){
            if(dist[a]+1 < dist[u]){
                dist[u] = dist[a] + 1;
                q.push(u);
            }
        }
    }

    ll cnt = 0;

    fo(i,1,n) if(dist[i] == 1 || dist[i] == 2) cnt++;

    cout out cnt;

    return 0;
}
