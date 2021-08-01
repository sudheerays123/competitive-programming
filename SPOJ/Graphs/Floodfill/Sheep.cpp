#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define vbl vector<bool>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
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
#define N 255

vector<vector<char>> grid(N,vector<char>(N));
vector<vector<bool>> visited(N,vector<bool>(N,false));
ll sheep = 0 , wolf = 0;
vi dx = {-1,0,1,0};
vi dy = {0,1,0,-1};
ll n,m;

void dfs(ll i , ll j){

    if(visited[i][j] == true || grid[i][j] == '#') return;
    visited[i][j] = true;

    if(grid[i][j] == 'k') sheep++;
    else if(grid[i][j] == 'v') wolf++;

    fo(t,0,3) {
        ll x = i+dx[t];
        ll y = j+dy[t];
        if(x >= 1 && x <= n && y >= 1 && y <= m) dfs(i+dx[t] , j+dy[t]);
    }
}

int main() {

    fast;

    cin in n in m;


    fo(i,1,n){
        fo(j,1,m){
            cin in grid[i][j];
        }
    }

    ll totalsheep = 0 , totalwolf = 0;

    fo(i,1,n){
        fo(j,1,m){
            if(visited[i][j] == true || grid[i][j] == '#') continue;

            sheep = 0;
            wolf = 0;

            dfs(i,j);

            if(sheep > wolf) totalsheep += sheep;
            else totalwolf += wolf;
        }
    }

    cout out totalsheep space totalwolf;

    return 0;
}
