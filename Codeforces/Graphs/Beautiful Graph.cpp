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
#define MOD 998244353
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
#define N 300005

vector<bool> visited(N,false);
bool possible = true;
vi color(N,-1);
ll white = 0 , black = 0;
vi adj[N];

void dfs(ll s , ll p , ll c){
    if(visited[s] == true) return;
    visited[s] = true;

    color[s] = c;
    if(c == 1) black++;
    else if(c == 2) white++;

    for(auto u : adj[s]){
        if(u == p) continue;

        if(color[u] == color[s] || possible == false){
            possible = false;
            return;
        }

        if(color[u] == -1) dfs(u,s,c == 1 ? 2 : 1);
    }
}

ll binary_expo(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

int main() {

    fast;

    tc{
        ll n,m;
        cin in n in m;

        fo(i,1,m){
            ll a,b;
            cin in a in b;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        ll ans = 1;

        fo(i,1,n){
            if(visited[i] == true) continue;

            white = 0 , black = 0;
            dfs(i,0,1);

            if(possible == false) break;
            ans = (ans * (binary_expo(2,black)+ binary_expo(2,white))%MOD)%MOD;
        }

        if(possible == false) cout out "0\n";
        else cout out ans%MOD nextline;

        possible = true;
        white = 0 , black = 0;
        fo(i,1,n) {
            adj[i].clear();
            color[i] = -1;
            visited[i] = false;
        }
    }

    return 0;
}
