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

vi color(N,-1);
vector<bool> visited(N,false);
vi type(N);
vi adj[N];

void dfs(ll s){
    if(visited[s] == true) return;
    visited[s] = true;

    for(auto u : adj[s]) {
        if(color[u] == color[s]) color[u] = 3;

        if(visited[u] == false){
            if(color[s] == 1) color[u] = 2;
            else if(color[s] == 2 || color[s] == 3) color[u] = 1;

            dfs(u);
        }
    }
}

int main() {

    fast;

    tc{
        ll n;
        cin in n;

        fo(i,1,n) {
            cin in type[i];
            color[i] = -1;
            visited[i] = false;
            adj[i].clear();
        }

        fo(i,2,n){
            if(type[i] != type[i-1]){
                adj[i].pb(i-1);
                adj[i-1].pb(i);
            }
        }

        if(type[1] != type[n]){
            adj[1].pb(n);
            adj[n].pb(1);
        }

        fo(i,1,n){
            if(visited[i] == false){
                color[i] = 1;
                dfs(i);
            }
        }

        cout out *max_element(color.begin()+1,color.begin()+n+1) nextline;
        fo(i,1,n) cout out color[i] spacef;
        cout nextline;
    }

    return 0;
}
