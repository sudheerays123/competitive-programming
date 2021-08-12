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
#define N 505

ll more;
vector<vector<bool>> visited(N,vector<bool>(N,false));
vector<vi> grid(N,vi(N,1));

void dfs(ll i, ll j){

    if(visited[i][j] == true || more <= 0 || grid[i][j] != 0) return;
    visited[i][j] = true;

    more--;
    grid[i][j] = 2;

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main() {

    fast;

    ll n,m,k;
    cin in n in m in k;

    ll s = 0 , sx , sy;

    fo(i,1,n){
        fo(j,1,m){
            char x;
            cin in x;

            grid[i][j] = (x == '#');

            if(grid[i][j] == 0) {
                s++;
                sx = i;
                sy = j;
            }
        }
    }

    more = s-k;

    dfs(sx,sy);

    fo(i,1,n){
        fo(j,1,m){
            if(grid[i][j] == 0) cout out "X";
            else if(grid[i][j] == 1) cout out "#";
            else cout out ".";
        }
        cout nextline;
    }

    return 0;
}
