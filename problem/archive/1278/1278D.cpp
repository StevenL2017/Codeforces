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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n), pts;
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
        pts.emplace_back(a[i].first, i);
        pts.emplace_back(a[i].second, i);
    }

    sorta(pts);
    set<pair<int, int>> s;
    vector<vi> e(n);
    int cnt = 0;
    for (auto [x, i]: pts) {
        if (s.count({x, i})) {
            s.erase({x, i});
        } else {
            auto y = a[i].second;
            for (auto [xx, j]: s) {
                if (xx > y) break;
                e[i].push_back(j);
                e[j].push_back(i);
                cnt++;
                if (cnt >= n) break;
            }
            if (cnt >= n) break;
            s.insert({y, i});
        }
    }

    if (cnt != n - 1) {
        cout << "NO\n";
        return;
    }

    vi vis(n, 0);
    function<void(int, int)> dfs = [&] (int u, int p) {
        vis[u] = 1;
        for (auto& v: e[u]) {
            if (v == p) continue;
            if (!vis[v]) dfs(v, u);
        }
    };
    dfs(0, -1);

    cnt = 0;
    rep(i, n) {
        cnt += vis[i];
    }

    if (cnt != n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}