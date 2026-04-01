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

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        long long comb = 1;

        for (int i = 0; i < n; i++) {
            res = (res + comb * nums[i]) % 10;
            comb = comb * (n - 1 - i) / (i + 1);
        }

        return res;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.triangularSum(nums);

    return 0;
}