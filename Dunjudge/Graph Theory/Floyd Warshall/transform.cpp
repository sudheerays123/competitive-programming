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

    string s;
    cin in s;

    vector<vi> dist(30,vi(30,INF));

    fo(i,1,26) dist[i][i] = 0;

    fo(i,1,m){

        ll c;
        char a,b;

        cin in a in b in c;
        mmin(dist[a-'a'+1][b-'a'+1],c);
    }

    fo(k,1,26){
        fo(i,1,26){
            fo(j,1,26){
                mmin(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    ll ans = 0;
    bool possible = true;

    fo(i,0,(n/2)-1){

        ll thisside = s[i]-'a'+1;
        ll otherside = s[n-i-1]-'a'+1;

        ll mincost = INF;

        fo(j,1,26) mmin(mincost,dist[thisside][j] + dist[otherside][j]);

        if(mincost == INF){
            possible = false;
            break;
        }

        ans += mincost;
    }

    if(possible == false) cout out "-1";
    else cout out ans;

    return 0;
}
