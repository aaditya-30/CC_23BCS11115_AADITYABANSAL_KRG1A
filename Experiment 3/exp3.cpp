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
   int n,a,b;
   cin>>n>>a>>b;
   int mod = 1e9+7;
        int l = 1LL *min(a,b);
        int r = 1LL * n* min(a,b);
        int lcm = 1LL * a*b/gcd(a,b);
        while(l<r){
            int mid = l+ (r-l)/2;
            int cnt = (mid/a)%mod + (mid/b)%mod-(mid/lcm)%mod;
            if(cnt<n){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l%mod;
   return 0;
}