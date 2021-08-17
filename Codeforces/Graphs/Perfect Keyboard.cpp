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

vector<bool> visited(35,false);
vector<vi> adj(35,vi(35,0));

void dfs(ll s){

    if(visited[s] == true) return;
    visited[s] = true;

    cout out char(s+96);

    fo(i,1,30) if(adj[s][i] == 1) dfs(i);
}

int main() {
    
    fast;

    tc{
        string s;
        cin in s;

        ll n = s.size();
        if(n == 1) adj[int(s[0])-96][int(s[0])-96] = 1;

        fo(i,0,n-2){
            adj[int(s[i])-96][int(s[i+1])-96] = 1;
            adj[int(s[i+1])-96][int(s[i])-96] = 1;
        }

        ll start = INF;
        bool possible = true;
        fo(i,1,30){
            ll cnt = 0;
            fo(j,1,30) if(adj[i][j] == 1) cnt++;

            if(cnt == 1) {
                start = i;
            }
            if(cnt >= 3){
                possible = false;
                break;
            }
        }

        if(start == INF || possible == false) cout out "NO\n";
        else{
            cout out "YES\n";

            dfs(start);

            fo(i,1,26) if(visited[i] == false) cout out char(i+96);
            cout nextline;
        }

        fo(i,1,30){
            fo(j,1,30){
                adj[i][j] = 0;
                visited[i] = false;
            }
        }
    }

    return 0;
}
