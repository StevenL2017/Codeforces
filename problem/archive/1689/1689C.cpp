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
    int n;
    cin >> n;
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi sz(n), f(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        int c1 = -1, c2 = -1;
        for (auto v : e[u]) {
            if (v == p) continue;
            dfs(v, u);
            sz[u] += sz[v] + 1;
            if (c1 == -1) c1 = v;
            else if (c2 == -1) c2 = v;
        }
        if (c1 >= 0 && c2 == -1) {
            f[u] = sz[c1];
        } else if (c2 >= 0) {
            f[u] = max(f[c1] + sz[c2], f[c2] + sz[c1]);
        }
    };
    dfs(0, -1);
    cout << f[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}