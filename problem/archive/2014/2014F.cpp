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
    int n, c;
    cin >> n >> c;
    vi a(n);
    in(a);
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<vector<ll>> f(n, vector<ll>(2));
    function<void(int, int)> dfs = [&] (int u, int p) {
        f[u][1] = a[u];
        for (auto v: e[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            f[u][0] += max(f[v][0], f[v][1]);
            f[u][1] += max(f[v][0], f[v][1] - 2 * c);
        }
    };
    dfs(0, -1);
    cout << max(f[0][0], f[0][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}