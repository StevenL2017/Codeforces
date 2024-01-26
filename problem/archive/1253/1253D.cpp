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
    int n, m;
    cin >> n >> m;
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi vis(n);
    function<pair<int, int>(int)> dfs = [&] (int u) -> pair<int, int> {
        pair<int, int> res = {u, u};
        vis[u] = 1;
        for (auto v : e[u]) {
            if (vis[v]) continue;
            auto nxt = dfs(v);
            res.first = min(res.first, nxt.first);
            res.second = max(res.second, nxt.second);
        }
        return res;
    };

    vector<pair<int, int>> a;    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            a.push_back(dfs(i));
        }
    }

    int ans = 0, pre = -1;
    for (auto item: a) {
        if (item.first <= pre) {
            ans++;
        }
        pre = max(pre, item.second);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}