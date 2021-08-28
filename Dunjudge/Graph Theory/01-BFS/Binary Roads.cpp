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

vector<pll> adj[N];
ll n;

ll bfs(){

    queue<pll> q;
    vi dist0(N,INF); // minimum distance if we come to the ith node with value 1 and change it to 0
    vi dist1(N,INF); // minimum distance if we come to the ith node with value 0 and change it to 1

    q.push(mp(1,0));
    q.push(mp(1,1));
    dist0[1] = 0;
    dist1[1] = 0;

    while(!q.empty()){
        ll a = q.front().first;
        ll b = q.front().second;
        q.pop();

        for(auto u : adj[a]){
            if(u.second == b){
                if(b == 0 && dist0[a] + 1 < dist1[u.first]){
                    dist1[u.first] = dist0[a]+1;
                    q.push(mp(u.first,1));
                }
                if(b == 1 && dist1[a] + 1 < dist0[u.first]) {
                    dist0[u.first] = dist1[a]+1;
                    q.push(mp(u.first,0));
                }
            }
        }
    }

    ll d = min(dist0[n],dist1[n]);

    if(d == INF) return -1;
    return d;
}

int main() {

    fast;

    ll m;
    cin in n in m;

    fo(i,1,m){
        ll a,b,v;
        cin in a in b in v;

        a++; b++;

        adj[a].pb(mp(b,v));
        adj[b].pb(mp(a,v));
    }

    cout out bfs();

    return 0;
}
