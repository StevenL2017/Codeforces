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
    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    vector<vi> e(n);
    vi deg(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (a == b) {
        cout << "NO" << endl;
        return;
    }

    vi on_loop(n, 1);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        on_loop[u] = 0;
        for (auto v: e[u]) {
            deg[v]--;
            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }

    if (on_loop[b]) {
        cout << "YES" << endl;
        return;
    }

    queue<pair<int, int>> qb;
    qb.emplace(b, 0);
    vi vis(n);
    int step = 0, first_to_loop = -1;
    while (!qb.empty()) {
        auto [u, c] = qb.front();
        qb.pop();
        if (on_loop[u]) {
            step = c;
            first_to_loop = u;
            break;
        }
        vis[u] = 1;
        for (auto v: e[u]) {
            if (vis[v]) {
                continue;
            }
            qb.emplace(v, c + 1);
        }
    }

    if (first_to_loop == -1) {
        cout << "NO" << endl;
        return;
    }

    queue<int> qa;
    qa.push(a);
    vi dist(n, 1e9);
    dist[a] = 0;
    while (!qa.empty()) {
        int u = qa.front();
        qa.pop();
        for (auto v: e[u]) {
            if (dist[v] <= dist[u] + 1) {
                continue;
            }
            dist[v] = dist[u] + 1;
            qa.push(v);
        }
    }

    cout << (dist[first_to_loop] <= step ? "NO" : "YES") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}