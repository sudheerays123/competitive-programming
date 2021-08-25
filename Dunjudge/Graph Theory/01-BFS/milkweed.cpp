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

    ll n,m,mx,my;
    cin in m in n in mx in my;

    my = n-my+1;

    ll sx = my;
    ll sy = mx;

    vector<vector<char>> grid(n+5,vector<char>(m+5,'*'));

    fo(i,1,n){
        fo(j,1,m){
            cin in grid[i][j];
        }
    }

    queue<pll> q;
    vector<vi> dist(n+5,vi(m+5,INF));

    q.push({sx,sy});
    dist[sx][sy] = 0;

    vi dx = {-1,1,0,0,1,1,-1,-1};
    vi dy = {0,0,-1,1,1,-1,1,-1};

    while(!q.empty()){
        ll a = q.front().first;
        ll b = q.front().second;
        q.pop();

        fo(t,0,7){
            ll aa = a+dx[t];
            ll bb = b+dy[t];

            if( aa < 1 || aa > n || bb < 1 || bb > m || grid[aa][bb] == '*' ) continue;
            if(dist[a][b] + 1 < dist[aa][bb]){
                dist[aa][bb] = dist[a][b] + 1;
                q.push({aa,bb});
            }
        }
    }

    ll ans = -INF;

    fo(i,1,n){
        fo(j,1,m){
            if(dist[i][j] != INF) mmax(ans,dist[i][j]);
        }
    }

    cout out ans;

    return 0;
}
