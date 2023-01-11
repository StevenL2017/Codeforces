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
    vector<vi> graph(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n, -1), depth(n, -1), loop;
    function<void(int, int)> dfs_loop = [&] (int node, int fa) {
        parent[node] = fa;
        depth[node] = fa >= 0 ? depth[fa] + 1 : 0;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            if (depth[nxt] == -1) dfs_loop(nxt, node);
            if (depth[node] > depth[nxt] && depth[node] - depth[nxt] < k && loop.empty()) {
                for (int i = node; i != parent[nxt]; i = parent[i]) {
                    loop.push_back(i + 1);
                }
            }
        }
    };
    dfs_loop(0, -1);

    if (!loop.empty()) {
        cout << 2 << endl << ssz(loop) << endl;
        out(loop);
        return;
    }

    vi ans;
    if (m == n - 1) {
        for (int x = 0; x < 2; x++) {
            ans.clear();
            rep(i, n) {
                if ((depth[i] & 1) == x && ssz(ans) < (k + 1) / 2) {
                    ans.push_back(i + 1);
                }
            }
            if (ssz(ans) == (k + 1) / 2) break;
        }
    } else {
        int x = 0;
        while (depth[x] + 1 < k) x++;
        for (int i = 0; i < (k + 1) / 2; i++, x = parent[parent[x]]) {
            ans.push_back(x + 1);
        }
    }
    cout << 1 << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}