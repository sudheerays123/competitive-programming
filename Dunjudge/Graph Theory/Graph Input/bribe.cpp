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

    vi bribe(n+5);
    fo(i,1,n) cin in bribe[i];

    ll e;
    cin in e;

    vi friends(n+5,0);

    fo(i,1,e){
        ll a,b;
        cin in a in b;

        friends[a]++;
        friends[b]++;
    }

    double best = -INF;
    ll bestfriend;

    fo(i,1,n){
        double p = (double)(friends[i]+1)/(double)bribe[i];

        if(p > best){
            best = p;
            bestfriend = i;
        }
    }

    cout out bestfriend;

    return 0;
}
