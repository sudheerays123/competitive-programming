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

    ll n;
    cin in n;

    vector<vi> dist(n+5,vi(n+5));

    fo(i,1,n){
        fo(j,1,n){
            cin in dist[i][j];
        }
    }

    fo(k,1,n){
        fo(i,1,n){
            fo(j,1,n){
                mmax(dist[i][j],min(dist[i][k],dist[k][j]));
            }
        }
    }

    ll ans = INF;

    fo(i,1,n){
        fo(j,1,n){
            if(dist[i][j] != 0) mmin(ans,dist[i][j]);
        }
    }

    if(ans == INF)  cout out 0;
    else cout out ans;

    return 0;
}
