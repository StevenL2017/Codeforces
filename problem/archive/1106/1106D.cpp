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
    int n, m; cin >> n >> m;
    vector<set<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (u == v || e[u].find(v) != e[u].end()) {
            continue;
        }
        e[u].insert(v);
        e[v].insert(u);
    }

    vi ans, vis(n, 0);
    set<int> s;
    function<void(int)> dfs = [&] (int u) {
        ans.push_back(u + 1);
        vis[u] = 1;
        s.erase(u);
        for (auto v : e[u]) {
            if (vis[v]) continue;
            s.insert(v);
        }
        if (!s.empty()) dfs(*s.begin());
    };
    s.insert(0);
    dfs(0);

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}