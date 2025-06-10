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
    int n, k;
    cin >> n >> k;
    vi mark(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        mark[x - 1] = 1;
    }
    vector<vi> e(n);
    vi deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vi removed(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1 && !mark[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        removed[u] = 1;
        for (auto v: e[u]) {
            if (removed[v] || mark[v]) {
                continue;
            }
            deg[v]--;
            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }

    int d = 0;
    vi f(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        for (auto v: e[u]) {
            if (v == p || removed[v]) {
                continue;
            }
            dfs(v, u);
            d = max(d, f[u] + f[v] + 1);
            f[u] = max(f[u], f[v] + 1);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!removed[i]) {
            dfs(i, -1);
            break;
        }
    }

    cout << (d + 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}