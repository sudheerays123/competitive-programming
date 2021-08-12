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
#define N 1005

int main() {

    fast;

    ll n,m,s,t;
    cin in n in m in s in t;

    vector<vi> adj(n+5,vi(n+5,0));

    fo(i,1,m){
        ll a,b;
        cin in a in b;

        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    queue<ll> q;
    vi d1(n+5,INF);

    q.push(s);
    d1[s] = 0;

    while(!q.empty()){
        ll a = q.front();
        q.pop();

        fo(u,1,n){
            if(adj[a][u] == 1){
                if(d1[a] + 1 < d1[u]){
                    d1[u] = d1[a] + 1;
                    q.push(u);
                }
            }
        }
    }

    vi d2(n+5,INF);

    q.push(t);
    d2[t] = 0;

    while(!q.empty()){
        ll a = q.front();
        q.pop();

        fo(u,1,n){
            if(adj[a][u] == 1){
                if(d2[a] + 1 < d2[u]){
                    d2[u] = d2[a] + 1;
                    q.push(u);
                }
            }
        }
    }

    ll cnt = 0;
    ll d = d1[t];

    fo(i,1,n)
        fo(j,i+1,n)
        if(adj[i][j] == 0 && d1[i]+1+d2[j] >= d && d1[j]+1+d2[i] >= d) cnt++;

    cout out cnt;

    return 0;
}
