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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

struct Flow {
    static constexpr int INF = 1e9;
    int n;
    struct Edge {
        int to, cap;
        Edge(int to, int cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    int maxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, INF);
        }
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);

    int tot = 0;
    vi cnt(n, 0);
    vector<vi> p(n);
    for (int i = 0; i < n; i++) {
        cnt[i] = tot;
        int x = a[i];
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                p[i].push_back(j);
                x /= j;
            }
        }
        if (x > 1) {
            p[i].push_back(x);
        }
        tot += ssz(p[i]);
    }

    int s = tot, t = tot + 1;
    Flow flow(tot + 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ssz(p[i]); j++) {
            if (i & 1) flow.addEdge(s, cnt[i] + j, 1);
            else flow.addEdge(cnt[i] + j, t, 1);
        }
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        if (!(u & 1)) swap(u, v);
        for (int i = 0; i < ssz(p[u]); i++) {
            for (int j = 0; j < ssz(p[v]); j++) {
                if (p[u][i] == p[v][j]) {
                    flow.addEdge(cnt[u] + i, cnt[v] + j, 1);
                }
            }
        }
    }

    cout << flow.maxFlow(s, t) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}