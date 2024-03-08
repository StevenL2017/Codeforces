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
    vector<set<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].insert(v);
        e[v].insert(u);
    }

    vi dist1(n, 2e9);
    dist1[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    pq1.emplace(0, 0);
    while (!pq1.empty()) {
        auto t = pq1.top();
        pq1.pop();
        int cost = t.first, x = t.second;
        if (dist1[x] < cost) continue;
        for (auto& y: e[x]) {
            auto d = dist1[x] + 1;
            if (d < dist1[y]) {
                dist1[y] = d;
                pq1.emplace(d, y);
            }
        }
    }

    vi dist2(n, 2e9);
    dist2[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    pq2.emplace(0, 0);
    while (!pq2.empty()) {
        auto t = pq2.top();
        pq2.pop();
        int cost = t.first, x = t.second;
        if (dist2[x] < cost) continue;
        for (int y = 0; y < n; y++) {
            if (e[x].count(y)) continue;
            auto d = dist2[x] + 1;
            if (d < dist2[y]) {
                dist2[y] = d;
                pq2.emplace(d, y);
            }
        }
    }

    if (dist1[n - 1] == 2e9 || dist2[n - 1] == 2e9) {
        cout << -1 << endl;
    } else {
        cout << max(dist1[n - 1], dist2[n - 1]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}