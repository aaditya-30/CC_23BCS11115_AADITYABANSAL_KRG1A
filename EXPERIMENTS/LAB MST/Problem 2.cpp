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
   
   vector<string> words(n);
   for(int i = 0; i < n; i++) {
       cin >> words[i];
   }
   vector<int> valid(n, 0);
    for(int i = 0; i < n; i++) {
        for(char c : words[i]) {
            valid[i] |= (1 << (c - 'a'));
        }
    }
    
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if((valid[i] & valid[j]) == 0) {
                int prod = (int)words[i].size() * (int)words[j].size();
                maxi = max(maxi, prod);
            }
        }
    }
    
    cout<<maxi<<endl;

   return 0;
}