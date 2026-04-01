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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            map<pair<int,int>, int> mp;
            int dup = 1;

            for(int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if(x1 == x2 && y1 == y2) {
                    dup++;
                    continue;
                }

                int dx = x2 - x1;
                int dy = y2 - y1;

                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                if(dx < 0) {
                    dx *= -1;
                    dy *= -1;
                } else if(dx == 0) {
                    dy = 1;
                } else if(dy == 0) {
                    dx = 1;
                }

                mp[{dx, dy}]++;
            }

            int maxi = 0;
            for(auto &it : mp) {
                maxi = max(maxi, it.second);
            }

            ans = max(ans, maxi + dup);
        }

        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution obj;
    cout << obj.maxPoints(points);

    return 0;
}