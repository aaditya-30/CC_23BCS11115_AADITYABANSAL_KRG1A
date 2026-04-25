#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#define endl "\n"
#define int long long
#define range(a) a.begin(),a.end()

const int MOD = 1e9 + 7;

// ------------------ UTILITY FUNCTIONS ------------------

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b){ return (a / gcd(a, b)) * b; }

bool isPrime(int n){
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

int fastPow(int a, int b, int mod){
    int res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<bool> sieve(int n){
    vector<bool> isPrime(n + 1, true);
    if(n >= 0) isPrime[0] = false;
    if(n >= 1) isPrime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int nCr(int n, int r){
    if(r > n) return 0;
    if(r > n - r) r = n - r;
    __int128 res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i) / (i + 1);
    }
    return (int)res;
}

int ndt(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for(auto& e : times) {
        int u=e[0];
        int v=e[1];
        int w=e[2];
        adj[u].push_back({v, w});
    } 
    vector<int> dist(n+1,INT_MAX);
    dist[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        
        if(d>dist[u]) continue;
        
        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    int maxTime = 0;
    for(int i = 1;i<=n; i++) {
        if(dist[i] == INT_MAX) {
            return -1;  
        }
        maxTime = max(maxTime, (int)dist[i]);
    }
    
    return maxTime;
}

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   
   vector<vector<int>> times1 = {{2,1,1}, {2,3,1}, {3,4,1}};
   int n = 4, k = 2;
   cout<<ndt(times1,n,k);

   return 0;
}