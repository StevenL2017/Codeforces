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
    vector<vi> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi dist(n, 0);
    int root = 0;
    function<void(int, int, int)> dfs = [&] (int u, int p, int d) {
        dist[u] = max(dist[u], d);
        if (dist[u] > dist[root]) {
            root = u;
        }
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1);
        }
    };
    dfs(0, -1, 0);

    rep(i, n) {
        dist[i] = 0;
    }
    dfs(root, -1, 0);
    dfs(root, -1, 0);

    int mx = *max_element(dist.begin(), dist.end());
    vi cnt(mx + 1, 0);
    rep(i, n) {
        cnt[dist[i]]++;
    }

    vi ans(n, n);
    int j = mx, tot = n;
    while (j > 0) {
        tot -= cnt[j];
        ans[--j] = tot + 1;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}