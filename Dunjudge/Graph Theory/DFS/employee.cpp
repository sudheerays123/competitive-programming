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
#define N 1000005

vector<bool> visited(N,false);
vi depth(N);
vi child[N];

void dfs(ll s){

    visited[s] = true;
    for(auto u : child[s]){
        if(visited[u] == false){
            depth[u] = depth[s] + 1;
            dfs(u);
        }
    }
}

int main() {

    fast;

    ll n;
    cin in n;

    fo(i,1,n-1){
        ll x;
        cin in x;

        x++;
        child[x].pb(i+1);
    }

    depth[1] = 1;
    dfs(1);

    ll ans = -INF;

    fo(i,1,n) mmax(ans,depth[i]);

    cout out ans;

    return 0;
}
