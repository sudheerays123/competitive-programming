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

    vector<pll> adj[n+5];

    fo(i,1,m){
        ll a,b,c;
        cin in a in b in c;

        a++; b++;

        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }

    priority_queue<pll> q;
    vi dist1(n+5,INF);
    vi distn(n+5,INF);
    vector<bool> visited1(n+5,false);
    vector<bool> visited2(n+5,false);

    q.push({0,1});
    dist1[1] = 0;

    while(!q.empty()){
        ll a = q.top().second;
        q.pop();

        if(visited1[a] == true) continue;
        visited1[a] = true;

        for(auto u : adj[a]){
            ll b = u.first;
            ll w = u.second;

            if(dist1[a] + w < dist1[b]){
                dist1[b] = dist1[a] + w;
                q.push({-dist1[b],b});
            }
        }
    }

    q.push({0,n});
    distn[n] = 0;

    while(!q.empty()){
        ll a = q.top().second;
        q.pop();

        if(visited2[a] == true) continue;
        visited2[a] = true;

        for(auto u : adj[a]){
            ll b = u.first;
            ll w = u.second;

            if(distn[a] + w < distn[b]){
                distn[b] = distn[a] + w;
                q.push({-distn[b],b});
            }
        }
    }

    ll qu;
    cin in qu;

    while(qu--){
        ll a,b;
        cin in a in b;

        a++; b++;

        ll ans = max(dist1[n]-dist1[a]-distn[b],dist1[n]-dist1[b]-distn[a])-1;

        if(ans >= 0) cout out ans nextline;
        else cout out "-1\n";
    }

    return 0;
}
