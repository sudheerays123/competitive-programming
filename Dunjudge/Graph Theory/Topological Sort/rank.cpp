#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    
    ll n,k;
    cin >> n >> k;

    vector<ll> adj[n+5];
    vector<ll> indegree(n+5,0);

    for(ll i = 1; i <= k; i++){
        ll a,b,c;
        char x;

        cin >> a >> x >> b >> x >> c;

        if(x == '>'){
            adj[a].push_back(c);
            adj[b].push_back(c);
        }
        else{
            adj[a].push_back(b);
            adj[a].push_back(c);
        }
    }

    for(ll i = 1; i <= n; i++){
        for(auto u : adj[i]){
            indegree[u]++;
        }
    }

    queue<ll> q;
    vector<ll> order;

    for(ll i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        ll a = q.front();
        q.pop();

        order.push_back(a);

        for(auto u : adj[a]){
            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
    }

    if(order.size() == n) for(auto u : order) cout << u << " ";
    else cout << 0;

    return 0;
}
