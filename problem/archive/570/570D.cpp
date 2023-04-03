#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> e(n);
    rep(i, n - 1) {
        int p; cin >> p;
        e[p - 1].push_back(i + 1);
    }
    string s; cin >> s;

    int tt = 0;
    vi tin(n), tout(n);
    vector<vi> row, cnt;
    function<void(int, int)> dfs = [&] (int u, int d) {
        tin[u] = tt++;
        if (ssz(row) == d) {
            row.push_back({});
            cnt.push_back({0});
        }
        row[d].push_back(tin[u]);
        cnt[d].push_back(cnt[d].back() ^ (1 << ((int)(s[u] - 'a'))));
        for (auto& v: e[u]) {
            dfs(v, d + 1);
        }
        tout[u] = tt;
    };
    dfs(0, 0);

    while (m--) {
        int v, h; cin >> v >> h;
        v--; h--;

        if (h >= ssz(row)) {
            cout << "Yes\n";
            continue;
        }

        auto left = lower_bound(row[h].begin(), row[h].end(), tin[v]) - row[h].begin();
        auto right = lower_bound(row[h].begin(), row[h].end(), tout[v]) - row[h].begin();
        int odd = __builtin_popcount(cnt[h][right] ^ cnt[h][left]);

        if (odd <= 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}