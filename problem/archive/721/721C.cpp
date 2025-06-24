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

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u - 1].emplace_back(v - 1, w);
    }

    vector<vi> dist(n, vi(n, t + 1));
    dist[n - 1][0] = 0;
    vector<vi> nxt(n, vi(n));
    vi vis(n);
    function<void(int)> dfs = [&] (int u) {
        vis[u] = 1;
        for (auto [v, w]: e[u]) {
            if (!vis[v]) {
                dfs(v);
            }
            for (int s = 0; s < n - 1; s++) {
                if (dist[u][s + 1] > dist[v][s] + w) {
                    dist[u][s + 1] = dist[v][s] + w;
                    nxt[u][s + 1] = v;
                }
            }
        }
    };
    dfs(0);

    int mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (dist[0][i] <= t) {
            mx = i;
            break;
        }
    }

    vi ans;
    int u = 0, s = mx;
    while (u != n - 1) {
        ans.push_back(u + 1);
        u = nxt[u][s--];
    }
    ans.push_back(n);

    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}