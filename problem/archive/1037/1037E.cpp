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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> e(m);
    vector<vector<pair<int, int>>> graph(n);
    vector<int> deg(n, 0);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[i].first = u;
        e[i].second = v;
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
        deg[u]++;
        deg[v]++;
    }

    set<pair<int, int>> s;
    vector<bool> valid(n, true);
    rep(i, n) {
        s.insert({deg[i], i});
    }

    auto update = [&] (int i) {
        while (!s.empty() && s.begin()->first < k) {
            int u = s.begin()->second;
            for (auto& nxt: graph[u]) {
                int v = nxt.first, idx = nxt.second;
                if (idx >= i) continue;
                if (valid[v]) {
                    s.erase({deg[v], v});
                    deg[v]--;
                    s.insert({deg[v], v});
                }
            }
            s.erase({deg[u], u});
            valid[u] = false;
        }
    };

    vi ans(m);
    update(m);
    repd(i, m - 1, -1) {
        ans[i] = ssz(s);
        int u = e[i].first, v = e[i].second;
        if (valid[u] && valid[v]) {
            s.erase({deg[u], u});
            deg[u]--;
            s.insert({deg[u], u});

            s.erase({deg[v], v});
            deg[v]--;
            s.insert({deg[v], v});

            update(i);
        }
    }

    rep(i, m) cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}