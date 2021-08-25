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

    ll n,s;
    cin in n in s;

    vi snake(n+5,INF);
    vi ladder(n+5,INF);

    fo(i,1,s){
        ll a,b;
        cin in a in b;

        if(a < b) ladder[a] = b;
        else snake[a] = b;
    }

    queue<ll> q;
    vi dist(n+5,INF);

    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        ll a = q.front();
        q.pop();

        fo(i,1,6){

            ll aa = a+i;
            if(aa > n) aa = n-i+(n-a);

            while(true){
                if(snake[aa] == INF && ladder[aa] == INF) break;
                else if(snake[aa] != INF) aa = snake[aa];
                else if(ladder[aa] != INF) aa = ladder[aa];
            }

            if(dist[a] + 1 < dist[aa]){
                dist[aa] = dist[a] + 1;
                q.push(aa);
            }
        }
    }

    if(dist[n] == INF) cout out "-1";
    else cout out dist[n];

    return 0;
}
