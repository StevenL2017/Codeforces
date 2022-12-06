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

void solve() {
    int n; cin >> n;
    vi c(n); in(c);
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<map<int, int>> cnt(n);
    vector<vector<ll>> sum(n);
    vector<ll> ans(n);
    auto merge = [&] (int u, int v) -> int {
        if (ssz(cnt[u]) < ssz(cnt[v])) swap(u, v);
        for (auto it: cnt[v]) {
            auto o = cnt[u][it.first];
            cnt[u][it.first] += it.second;
            repa(x, 1, it.second + 1) {
                if (o + x >= ssz(sum[u])) sum[u].push_back(0);
                sum[u][o + x] += it.first;
            }
        }
        return u;
    };
    function<void(int, int)> dfs = [&] (int node, int fa) {
        cnt[node][c[node]] = 1;
        sum[node] = {0, c[node]};
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs(nxt, node);
            auto w = merge(node, nxt);
            if (w != node) {
                cnt[node] = move(cnt[w]);
                sum[node] = move(sum[w]);
            }
        }
        ans[node] = *sum[node].rbegin();
    };
    dfs(0, -1);

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}