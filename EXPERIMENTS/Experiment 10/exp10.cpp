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
vector<int> countSmaller(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);

    tree<pair<int,int>, null_type, less<pair<int,int>>,
         rb_tree_tag, tree_order_statistics_node_update> st;

    for(int i = n-1;i>=0;i--){
        ans[i] = st.order_of_key({nums[i], i});
        st.insert({nums[i], i});
    }
    return ans;
}
signed main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
cin >> n;
vector<int> nums(n);
for(int i = 0; i < n; i++) cin >> nums[i];

vector<int> res = countSmaller(nums);

for(int x : res) cout << x << " ";
cout << endl;
   return 0;
}