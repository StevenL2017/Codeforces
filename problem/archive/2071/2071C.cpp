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
    int n, s, e;
    cin >> n >> s >> e;
    s--; e--;
    vector<vi> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi d(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        if (p != -1) {
            d[u] = d[p] + 1;
        }
        for (auto v: g[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
        }
    };
    dfs(e, -1);

    vi idx(n);
    iota(begin(idx), end(idx), 1);
    sort(begin(idx), end(idx), [&] (int i, int j) { return d[i - 1] > d[j - 1]; });
    out(idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}