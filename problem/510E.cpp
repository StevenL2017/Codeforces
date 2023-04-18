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

struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
    int n, m;
    vector<Edge> e;
    int fir[MAXN];
    int dep[MAXN];
    int cur[MAXN];

    void init(int n) {
        this->n = n;
        this->m = 0;
        memset(fir, -1, sizeof(int) * n);
        e.clear();
    }

    void add_edge(int from, int to, int cap) {
        e.push_back(Edge(to, fir[from], cap, 0));
        fir[from] = m++;
        e.push_back(Edge(from, fir[to], 0, 0));
        fir[to] = m++;
    }

    bool bfs(int s, int t) {
        queue<int> q;
        memset(dep, 0, sizeof(int) * n);
        dep[s] = 1;
        q.push(s);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u]; ~i; i = e[i].to) {
                int v = e[i].from;
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
        for (int& i = cur[u]; ~i; i = e[i].to) {
            int v = e[i].from, d;
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
            memcpy(cur, fir, sizeof(int) * n);
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

    cout << flow << endl;

    // vector<vi> ans;

    // cout << ssz(ans) << endl;
    // rep(i, ssz(ans)) {
    //     cout << ssz(ans[i]) << " ";
    //     out(ans[i]);
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}