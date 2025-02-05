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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--; b--;
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi vis(n);
    function<void(int, int)> dfs = [&] (int u, int k) {
        if (k == 0 && u == a || k == 1 && u == b) {
            return;
        }
        vis[u] |= 1 << k;
        for (auto v: e[u]) {
            if (vis[v] >> k & 1) {
                continue;
            }
            dfs(v, k);
        }
    };
    dfs(b, 0);
    dfs(a, 1);

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (i == a || i == b) {
            continue;
        }
        if (vis[i] == 1) {
            c1++;
        } else if (vis[i] == 2) {
            c2++;
        }
    }
    cout << c1 * 1ll * c2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}