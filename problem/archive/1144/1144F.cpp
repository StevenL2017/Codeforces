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
    int n, m; cin >> n >> m;
    vector<vi> e(n);
    vector<pair<int, int>> edges;
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        edges.emplace_back(u, v);
    }

    vi color(n, -1);
    function<void(int, int, int)> dfs = [&] (int u, int p, int c) {
        color[u] = c;
        for (auto& v: e[u]) {
            if (v == p || color[v] != -1) continue;
            dfs(v, u, c ^ 1);
        }
    };
    dfs(0, -1, 0);

    string ans;
    for (auto& [u, v]: edges) {
        if (color[u] == color[v]) {
            cout << "NO\n";
            return;
        }
        if (color[u]) ans += '0';
        else ans += '1';
    }

    cout << "YES\n";
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}