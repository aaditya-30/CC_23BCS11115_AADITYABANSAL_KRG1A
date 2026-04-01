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
   cin>>n;
   vpii a(n);
   for(int i = 0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    int m;
    cin>>m;
    vpii b(m);
    for(int i = 0;i<m;i++)
    {
        cin>>b[i].first>>b[i].second;
     }
     
    
   return 0;
}