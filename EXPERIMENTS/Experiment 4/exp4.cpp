#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#define endl "\n"
#define int long long
#define range(a) a.begin(),a.end()
#define inputarr(a) for(int i = 0;i<n;i++) cin>>a[i]

using umii  = unordered_map<int,int>;
using vpii = vector<pair<int,int>>;
using pii = pair<int,int>;
using vi = vector<int>;
const int MOD = 1e9 + 7;

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
    cin >> n;   
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];    
    long long ans = 0;  
    for (int i = 0; i < 32; i++) {
        long long c1 = 0;
        for (int x : nums) {
            if (x & (1LL << i)) c1++;
        }
        long long c0 = n - c1;
        ans += c1 * c0;
    }   
    cout << ans*2 << "\n";
   return 0;
}