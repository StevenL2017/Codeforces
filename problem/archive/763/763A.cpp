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
    vi a(n);
    in(a);

    int c1 = -1, c2 = -1;
    queue<int> q;
    vi vis(n);
    q.push(0);
    while (!q.empty() && c1 == -1) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (auto v: e[u]) {
            if (vis[v]) continue;
            if (a[u] != a[v]) {
                c1 = u;
                c2 = v;
                break;
            }
            q.push(v);
        }
    }

    if (c1 == -1) {
        cout << "YES\n" << 1 << endl;
        return;
    }

    function<bool(int, int, int)> dfs = [&] (int u, int p, int c) -> bool {
        if (a[u] != c) return false;
        for (auto v: e[u]) {
            if (v == p) continue;
            if (!dfs(v, u, c)) return false;
        }
        return true;
    };

    auto calc = [&] (int u) -> bool {
        for (auto v: e[u]) {
            if (!dfs(v, u, a[v])) {
                return false;
            }
        }
        return true;
    };

    if (calc(c1)) {
        cout << "YES\n" << c1 + 1 << endl;
        return;
    }
    if (calc(c2)) {
        cout << "YES\n" << c2 + 1 << endl;
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}