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
    vector<vi> cost(3, vi(n));
    rep(i, 3) in(cost[i]);
    vector<vi> e(n);
    vi deg(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int root = -1;
    rep(i, n) {
        if (deg[i] > 2) {
            cout << -1 << endl;
            return;
        }
        if (deg[i] == 1) {
            root = i;
        }
    }

    vi a;
    function<void(int, int)> dfs = [&] (int u, int p) {
        a.push_back(u);
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
    };
    dfs(root, -1);

    ll mn = LLONG_MAX;
    vi pattern;
    rep(i, 3) {
        rep(j, 3) {
            if (j == i) continue;
            rep(k, 3) {
                if (k == i || k == j) continue;
                ll cur = 0;
                vi b = {i + 1, j + 1, k + 1};
                rep(l, n) {
                    cur += cost[b[l % 3] - 1][a[l]];
                }
                if (cur < mn) {
                    mn = cur;
                    pattern = b;
                }
            }
        }
    }

    vi ans(n);
    rep(i, n) {
        ans[a[i]] = pattern[i % 3];
    }

    cout << mn << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}