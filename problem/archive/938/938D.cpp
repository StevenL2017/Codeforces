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
    vector<vector<pair<int, ll>>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    vector<ll> a(n); in(a);

    priority_queue<pair<ll, int>> q;
    for (int i = 0; i < n; i++) {
        q.emplace(-a[i], i);
    }
    while (!q.empty()) {
        auto [cost, u] = q.top();
        q.pop();
        if (-cost > a[u]) continue;
        for (auto [v, w] : e[u]) {
            if (a[v] > a[u] + w * 2) {
                a[v] = a[u] + w * 2;
                q.emplace(-a[v], v);
            }
        }
    }

    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}