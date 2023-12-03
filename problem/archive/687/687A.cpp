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

    vi vis(n, -1);
    function<void(int, int)> dfs = [&] (int u, int p) {
        for (auto v: e[u]) {
            if (v == p) continue;
            if (vis[v] != -1 && vis[v] == vis[u] ^ 1) continue;
            if (vis[v] != -1 && vis[v] != vis[u] ^ 1) {
                vis[v] = -2;
                return;
            }
            vis[v] = vis[u] ^ 1;
            dfs(v, u);
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            vis[i] = 0;
            dfs(i, -1);
        }
    }

    vi ans1, ans2;
    for (int i = 0; i < n; i++) {
        if (vis[i] == -2) {
            cout << -1 << endl;
            return;
        }
        if (vis[i] == 0) ans1.emplace_back(i + 1);
        else if (vis[i] == 1) ans2.emplace_back(i + 1);
    }

    cout << ssz(ans1) << endl;
    out(ans1);
    cout << ssz(ans2) << endl;
    out(ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}