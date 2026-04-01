#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<pair<int,int>, int> mp;
            int duplicate = 0;
            int currMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // duplicate point
                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // normalize sign
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                } else if (dx == 0) {
                    dy = 1;  // vertical
                } else if (dy == 0) {
                    dx = 1;  // horizontal
                }

                mp[{dx, dy}]++;
                currMax = max(currMax, mp[{dx, dy}]);
            }

            ans = max(ans, currMax + duplicate + 1);
        }

        return ans;
    }
};