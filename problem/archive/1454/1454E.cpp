#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
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

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vector<vi> graph(n);
    rep(i, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vi parent(n, -1), depth(n, 0), in_loop(n, 0);
    function<void(int, int)> dfs = [&] (int node, int fa) {
        parent[node] = fa;
        depth[node] = (fa == -1 ? 1 : depth[fa] + 1);
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            if (depth[nxt] == 0) dfs(nxt, node);
            if (depth[node] > depth[nxt]) {
                auto temp = node;
                while (temp != nxt) {
                    in_loop[temp] = 1;
                    temp = parent[temp];
                }
                in_loop[nxt] = 1;
            }
        }
    };
    dfs(0, -1);

    ll ans = 0;
    rep(i, n) {
        if (!in_loop[i]) continue;
        function<int(int, int)> sz = [&] (int node, int fa) -> int {
            int cnt = 1;
            for (auto& nxt: graph[node]) {
                if (nxt == fa || in_loop[nxt]) continue;
                cnt += sz(nxt, node);
            }
            return cnt;
        };
        auto c = sz(i, -1);
        ans += 1ll * c * (c - 1) / 2;
        ans += 1ll * c * (n - c);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}