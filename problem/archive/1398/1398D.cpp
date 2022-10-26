#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD
#define endl '\n'

#define ll long long
#define vi vector<int>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    vi rr(r), gg(g), bb(b);
    rep(i, r) cin >> rr[i];
    rep(i, g) cin >> gg[i];
    rep(i, b) cin >> bb[i];

    sortD(rr);
    sortD(gg);
    sortD(bb);

    int ans = 0;
    vector<vector<vi>> f(r + 1, vector<vi>(g + 1, vi(b + 1, 0)));
    rep(i, r + 1) {
        rep(j, g + 1) {
            rep(k, b + 1) {
                if (i > 0 && j > 0) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + rr[i - 1] * gg[j - 1]);
                }
                if (i > 0 && k > 0) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + rr[i - 1] * bb[k - 1]);
                }
                if (j > 0 && k > 0) {
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 1] + gg[j - 1] * bb[k - 1]);
                }
                ans = max(ans, f[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}