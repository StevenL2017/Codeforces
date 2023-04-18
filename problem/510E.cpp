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

const int MAXN = 2e2 + 3;

// Dinic 算法
struct Dinic {
    struct Edge {
        int v, nxt, cap, flow;
    } e[MAXN * MAXN];

    int n, m;
    int fir[MAXN];
    int dep[MAXN];
    int cur[MAXN];

    void init(int n) {
        memset(fir, -1, sizeof(fir));
        m = 0;
        this->n = n;
    }

    void add_edge(int u, int v, int w) {
        e[m] = {v, fir[u], w, 0};
        fir[u] = m++;
        e[m] = {u, fir[v], 0, 0};
        fir[v] = m++;
    }

    bool bfs(int s, int t) {
        queue<int> q;
        memset(dep, 0, sizeof(int) * (n + 1));
        dep[s] = 1;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u]; ~i; i = e[i].nxt) {
                int v = e[i].v;
                if ((!dep[v]) && (e[i].cap > e[i].flow)) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[t];
    }

    int dfs(int u, int t, int bound) {
        if ((u == t) || (!bound)) return bound;
        int ret = 0;
        for (int& i = cur[u]; ~i; i = e[i].nxt) {
            int v = e[i].v, d;
            if ((dep[v] == dep[u] + 1) && (d = dfs(v, t, min(bound - ret, e[i].cap - e[i].flow)))) {
                ret += d;
                e[i].flow += d;
                e[i ^ 1].flow -= d;
                if (ret == bound) return ret;
            }
        }
        return ret;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            memcpy(cur, fir, sizeof(int) * (n + 1));
            flow += dfs(s, t, INT_MAX);
        }
        return flow;
    }
};

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vi odd, even;
    rep(i, n) {
        if (a[i] & 1) odd.push_back(i);
        else even.push_back(i);
    }

    if (ssz(odd) != ssz(even)) {
        cout << "Impossible\n";
        return;
    }

    Dinic dinic;
    dinic.init(n + 2);
    int s = n, t = n + 1;
    for (auto& x: odd) {
        dinic.add_edge(s, x, 2);
    }
    for (auto& x: even) {
        dinic.add_edge(x, t, 2);
    }
    for (auto& x: odd) {
        for (auto& y: even) {
            if (is_prime(a[x] + a[y])) {
                dinic.add_edge(x, y, 1);
            }
        }
    }
    int flow = dinic.max_flow(s, t);

    if (flow != n) {
        cout << "Impossible\n";
        return;
    }

    vector<vi> b(n);
    for (auto& u: odd) {
        for (int i = dinic.fir[u]; ~i; i = dinic.e[i].nxt) {
            int v = dinic.e[i].v;
            if (dinic.e[i].flow && v != s && v != t) {
                b[u].push_back(v);
                b[v].push_back(u);
            }
        }
    }

    vector<vi> ans;
    vi vis(n, 0);
    rep(i, n) {
        if (vis[i]) continue;
        vi cur;
        int x = i;
        while (!vis[x]) {
            cur.push_back(x + 1);
            vis[x] = 1;
            if (!vis[b[x][0]]) x = b[x][0];
            else x = b[x][1];
        }
        ans.push_back(cur);
    }

    cout << ssz(ans) << endl;
    rep(i, ssz(ans)) {
        cout << ssz(ans[i]) << " ";
        out(ans[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}