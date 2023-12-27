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
    vi a(n); in(a);
    vector<vi> s(n);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            s[x - 1].push_back(i);
        }
    }

    vector<vector<pair<int, int>>> e(m);
    for (int i = 0; i < n; i++) {
        int u = s[i][0], v = s[i][1];
        e[u].emplace_back(v, a[i]);
        e[v].emplace_back(u, a[i]);
    }

    bool ok = true;
    vi vis(m), color(m, -1);
    for (int i = 0; i < m; i++) {
        if (vis[i] || !ssz(e[i])) {
            continue;
        }
        vis[i] = 1;
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, r]: e[u]) {
                int c = color[u];
                if (r == 0) c ^= 1;
                if (vis[v] && color[v] != c) {
                    ok = false;
                }
                if (!vis[v]) {
                    vis[v] = 1;
                    color[v] = c;
                    q.push(v);
                }
            }
        }
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}