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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    s1--; s2--;
    vector<vi> e1(n), e2(n);
    set<pair<int, int>> sp1, sp2;
    int m1;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e1[u].push_back(v);
        e1[v].push_back(u);
        sp1.emplace(min(u, v), max(u, v));
    }
    int m2;
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e2[u].push_back(v);
        e2[v].push_back(u);
        sp2.emplace(min(u, v), max(u, v));
    }

    vector<vi> d(n, vi(n, 1e9));
    d[s1][s2] = 0;
    set<pair<int, pair<int, int>>> q;
    q.insert({0, {s1, s2}});
    while (!q.empty()) {
        auto [u1, u2] = q.begin()->second;
        q.erase(q.begin());
        for (auto v1: e1[u1]) {
            for (auto v2: e2[u2]) {
                if (d[v1][v2] > d[u1][u2] + abs(v1 - v2)) {
                    q.erase({d[v1][v2], {v1, v2}});
                    d[v1][v2] = d[u1][u2] + abs(v1 - v2);
                    q.insert({d[v1][v2], {v1, v2}});
                }
            }
        }
    }

    int ans = 1e9;
    for (auto p: sp1) {
        if (!sp2.count(p)) {
            continue;
        }
        ans = min(ans, d[p.first][p.first]);
        ans = min(ans, d[p.second][p.second]);
    }

    cout << (ans < 1e9 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}