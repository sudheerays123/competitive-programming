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

    ll n,m,k;
    cin in n in m in k;

    vi army[m+5];

    fo(i,1,m+1){
        ll x;
        cin in x;

        fo(bit,0,n) if(x & (1 << bit)) army[i].pb(bit+1);
    }

    ll cnt = 0;
    fo(i,1,m+1) sort(army[i].begin(),army[i].end());

    fo(i,1,m){
        ll diff = 0;

        for(auto u : army[m+1]){
            if(binary_search(army[i].begin(),army[i].end(),u) == false) diff++;
        }
        for(auto u : army[i]){
            if(binary_search(army[m+1].begin(),army[m+1].end(),u) == false) diff++;
        }

        if(diff <= k ) cnt++;
    }

    cout out cnt;

    return 0;
}
