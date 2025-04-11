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

const int N = 3001;
const int INF = 1e9;
ll dist[N * N], path[N * N];

void bfs(int n, vector<vector<int>>& e, int start, set<ll>& invalid) {
    fill(dist, dist + n * n, INF);
    queue<int> q;
    vi vis(n * n);
    for (auto v: e[0]) {
        q.push(v);
        vis[v] = 1;
        dist[v] = 1;
    }
    while (!q.empty()) {
        auto x = q.front();
        int pre = x / n, cur = x % n;
        if (cur == n - 1) {
            return;
        }
        q.pop();
        for (auto& nxt: e[cur]) {
            long long d = dist[x] + 1;
            int y = cur * n + nxt;
            if (d < dist[y] && !invalid.count(x * 1ll * n + nxt) && !vis[y]) {
                dist[y] = d;
                path[y] = x;
                vis[y] = 1;
                q.push(y);
            }
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    set<ll> invalid;
    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;
        invalid.insert((x * n + y) * 1ll * n + z);
    }

    bfs(n, e, 0, invalid);

    int mn = INF, cur = n * n;
    for (int i = 0; i < n; i++) {
        int z = i * n + n - 1;
        if (dist[z] < mn) {
            mn = dist[z];
            cur = z;
        }
    }
    if (mn == INF) {
        cout << -1 << endl;
        return;
    }

    vi ans(1, n);
    while (cur / n != 0) {
        ans.push_back(cur / n + 1);
        cur = path[cur];
    }
    ans.push_back(1);
    reverse(begin(ans), end(ans));

    cout << mn << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}