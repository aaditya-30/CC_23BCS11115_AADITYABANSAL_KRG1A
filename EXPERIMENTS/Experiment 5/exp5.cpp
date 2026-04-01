#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll P = 31;
const ll MOD = 1000000007;

ll hashStr(const string &s) {
    ll h = 0;
    ll power = 1;

    for (char c : s) {
        h = (h + (c - 'a' + 1) * power) % MOD;
        power = (power * P) % MOD;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<ll> st;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(hashStr(s));
    }

    while (m--) {
        string q;
        cin >> q;
        bool found = false;

        for (int i = 0; i < q.size() && !found; i++) {
            char original = q[i];

            for (char c = 'a'; c <= 'c'; c++) {
                if (c == original) continue;

                q[i] = c;

                if (st.count(hashStr(q))) {
                    found = true;
                    break;
                }
            }

            q[i] = original;
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}