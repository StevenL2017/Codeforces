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
    int n; cin >> n;
    vi a(n); in(a);
    vector<vi> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ans = 0;
    vector<vector<pair<int, int>>> f(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        vector<pair<int, int>> nxt;
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
            for (auto it: f[v]) {
                nxt.push_back(it);
            }
        }

        sorta(nxt);
        for (int i = 0, j = 0; i < ssz(nxt); ) {
            int mx1 = 0, mx2 = 0;
            while (j < ssz(nxt) && nxt[j].first == nxt[i].first) {
                j++;
                if (nxt[j - 1].second > mx1) {
                    mx2 = mx1;
                    mx1 = nxt[j - 1].second;
                }
                else if (nxt[j - 1].second > mx2) {
                    mx2 = nxt[j - 1].second;
                }
            }
            if (a[u] % nxt[i].first == 0) {
                ans = max(ans, mx1 + mx2 + 1);
                f[u].emplace_back(nxt[i].first, mx1 + 1);
            } else {
                ans = max(ans, mx1);
            }
            while (a[u] % nxt[i].first == 0) {
                a[u] /= nxt[i].first;
            }
            i = j;
        }

        for (int x = 2; x * x <= a[u]; x++) {
            if (a[u] % x == 0) {
                f[u].emplace_back(x, 1);
                ans = max(ans, 1);
                while (a[u] % x == 0) {
                    a[u] /= x;
                }
            }
        }

        if (a[u] > 1) {
            f[u].emplace_back(a[u], 1);
            ans = max(ans, 1);
        }
    };
    dfs(0, -1);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}