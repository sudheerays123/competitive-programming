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

    ll n,e,q;
    cin in n in e in q;

    vector<vi> adj(n+5,vi(n+5,INF));
    vector<vi> dist(n+5,vi(n+5,INF));

    fo(i,1,e){
        ll a,b,c;
        cin in a in b in c;

        adj[a][b] = c;
        adj[b][a] = c;
    }

    fo(i,0,n-1){
        fo(j,0,n-1){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = adj[i][j];
        }
    }

    fo(k,0,n-1){
        fo(i,0,n-1){
            fo(j,0,n-1){
                mmin(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    while(q--){
        ll a,b;
        cin in a in b;

        if(dist[a][b] == INF) cout out "-1\n";
        else cout out dist[a][b] nextline;
    }

    return 0;
}
