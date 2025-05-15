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
    ll k;
    cin >> n >> m >> k;
    vi a(n);
    in(a);
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
    }

    auto filter = [&] (int x) -> vector<vi> {
        vector<vi> ans(n);
        for (int i = 0; i < n; i++) {
            if (a[i] > x) continue;
            for (auto j: e[i]) {
                if (a[j] > x) continue;
                ans[i].push_back(j);
            }
        }
        return ans;
    };

    auto check_cycle = [&] (int x, vector<vi>& g) -> bool {
        vi vis(n), p;
        function<void(int)> dfs = [&] (int u) {
            vis[u] = 1;
            for (auto v: g[u]) {
                if (vis[v]) continue;
                dfs(v);
            }
            p.push_back(u);
        };
        for (int i = 0; i < n; i++) {
            if (a[i] > x || vis[i]) continue;
            dfs(i);
        }
        reverse(begin(p), end(p));
        vi idx(n);
        for (int i = 0; i < ssz(p); i++) {
            idx[p[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > x) continue;
            for (int j: g[i]) {
                if (idx[i] > idx[j]) {
                    return true;
                }
            }
        }
        return false;
    };

    auto calc_longest_path = [&] (int x, vector<vi>& g) -> int {
        int ans = 0;
        vi deg(n);
        for (int i = 0; i < n; i++) {
            if (a[i] > x) continue;
            for (int j: g[i]) {
                deg[j]++;
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (a[i] <= x && deg[i] == 0) {
                q.emplace(i, 1);
            }
        }
        while (!q.empty()) {
            auto [u, s] = q.front();
            q.pop();
            ans = max(ans, s);
            for (auto v: g[u]) {
                deg[v]--;
                if (deg[v] == 0) {
                    q.emplace(v, s + 1);
                }
            }
        }
        return ans;
    };

    auto check = [&] (int mid) -> bool {
        auto g = filter(mid);
        return check_cycle(mid, g) || (calc_longest_path(mid, g) >= k);
    };

    int left = 1, right = 1e9 + 1;
    int ans = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << (ans <= 1e9 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}