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
#define N 105

int main() {

    fast;

    tc{

        ll n;
        cin in n;

        vector<vi> grid(n+5,vi(n+5));

        fo(i,1,n){
            fo(j,1,n){
                cin in grid[i][j];
                grid[i][j]++;
            }
        }

        ll sx , sy , ex , ey;
        cin in sx in sy in ex in ey;
        sx++; sy++; ex++; ey++;

        ll ans = INF;

        fo(subset,1,1024){

            vi boss;
            fo(bit,0,10) if(subset & (1 << bit)) boss.pb(bit+1);

            if(boss.size() >= ans) continue;
            sort(boss.begin(),boss.end());

            queue<pll> q;
            vector<vector<bool>> possible(n+5,vector<bool>(n+5,false));

            vi dx = {-1,1,0,0};
            vi dy = {0,0,-1,1};

            if(binary_search(boss.begin(),boss.end(),grid[sx][sy]) == true){
                q.push({sx,sy});
                possible[sx][sy] = true;
            }

            while(!q.empty()){
                ll a = q.front().first;
                ll b = q.front().second;
                q.pop();

                fo(t,0,3){
                    ll aa = a+dx[t];
                    ll bb = b+dy[t];

                    if(aa >= 1 && aa <= n && bb >= 1 && bb <= n && possible[aa][bb] == false && binary_search(boss.begin(),boss.end(),grid[aa][bb]) == true){
                        possible[aa][bb] = true;
                        q.push({aa,bb});
                    }
                }
            }

            if(possible[ex][ey] == true) ans = boss.size();
        }

        cout out ans nextline;
    }

    return 0;
}
