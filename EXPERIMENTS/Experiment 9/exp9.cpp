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

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // LCS DP
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Build SCS from DP
    int i = n, j = m;
    string res = "";

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            res += s1[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            res += s1[i-1];
            i--;
        }
        else{
            res += s2[j-1];
            j--;
        }
    }

    while(i > 0){
        res += s1[i-1];
        i--;
    }
    while(j > 0){
        res += s2[j-1];
        j--;
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

   return 0;
}