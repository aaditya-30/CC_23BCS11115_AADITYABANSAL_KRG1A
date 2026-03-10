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
   vector<vi> energy(n, vector<int>(2));
   for(int i = 0;i<n;i++)
   {
    cin>>energy[i][0]>>energy[i][1];
   }
   sort(range(energy), [&](auto a, auto b)
{
    return (b[1]-b[0])-(a[1]-a[0]);
});
    int curr = 0;
    int sum = 0;
    for(auto it:energy)
    {
        if(curr<it[1])
        {
            sum+=it[1]-curr;
            curr = it[1];
        }
        curr-=it[0];
    }
    cout<<sum<<endl;
   return 0;
}