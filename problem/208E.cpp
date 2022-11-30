#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

const int MAXN = 1e5 + 3;

vector<int> graph[MAXN], level[MAXN];
int depth[MAXN], f[MAXN][31];
int tin[MAXN], tout[MAXN];
int tt = 0;

// 用来为 lca 算法做准备，编号 1 ~ n
void dfs(int node, int fa) {
    // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1
    f[node][0] = fa;
    depth[node] = fa > -1 ? depth[f[node][0]] + 1 : 0;
    tin[node] = tt++;
    level[depth[node]].push_back(tin[node]);
    // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
    // 2^(i-1) 的祖先节点
    for (int i = 1; i < 31; i++) {
        f[node][i] = fa > -1 ? f[f[node][i - 1]][i - 1] : -1;
    }
    // 遍历子节点来进行 dfs
    int sz = graph[node].size();
    for (int i = 0; i < sz; i++) {
        if (graph[node][i] == fa) continue;
        dfs(graph[node][i], node);
    }
    tout[node] = tt;
}

int find_pth_parent(int x, int p) {
    for (int i = 0; i < 31; i++) {
        if (p >> i & 1) {
            x = f[x][i];
        }
    }
    return x;
}

void solve() {
    int n; cin >> n;
    rep(i, n) {
        int x; cin >> x;
        graph[x].push_back(i + 1);
    }
    dfs(0, -1);

    int m; cin >> m;
    vi ans(m, 0);
    rep(i, m) {
        int v, p; cin >> v >> p;
        if (p >= depth[v]) continue;
        auto x = find_pth_parent(v, p);
        auto l = tin[x], r = tout[x];
        ans[i] = lower_bound(level[depth[v]].begin(), level[depth[v]].end(), r) - lower_bound(level[depth[v]].begin(), level[depth[v]].end(), l) - 1;
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