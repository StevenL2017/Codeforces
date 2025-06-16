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

    if (n == 2) {
        cout << "2 2\n1 1" << endl;
        return;
    }

    vi pa(n, -1);
    function<void(int, int)> dfs = [&] (int u, int p) {
        pa[u] = p;
        for (auto v: e[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
        }
    };
    dfs(0, -1);

    vector<vector<pair<int, int>>> f(n, vector<pair<int, int>>(2, {-1, -1}));
    function<void(int, int)> dp = [&] (int u, int op) {
        if (f[u][op].first >= 0) {
            return;
        }
        f[u][op] = {op, op ? -ssz(e[u]) : -1};
        for (auto v: e[u]) {
            if (v == pa[u]) {
                continue;
            }
            dp(v, 0);
            auto nxt = f[v][0];
            if (op == 0) {
                dp(v, 1);
                nxt = max(nxt, f[v][1]);
            }
            f[u][op].first += nxt.first;
            f[u][op].second += nxt.second;
        }
    };
    dp(0, 0);
    dp(0, 1);
    auto ans = max(f[0][0], f[0][1]);

    vi is_good(n);
    function<void(int, pair<int, int>)> build = [&] (int u, pair<int, int> val) {
        if (f[u][0] == val) {
            is_good[u] = 0;
            for (auto v: e[u]) {
                if (v == pa[u]) {
                    continue;
                }
                build(v, max(f[v][0], f[v][1]));
            }
        } else {
            is_good[u] = 1;
            for (auto v: e[u]) {
                if (v == pa[u]) {
                    continue;
                }
                build(v, f[v][0]);
            }
        }
    };
    build(0, ans);

    cout << ans.first << " " << -ans.second << endl;
    for (int i = 0; i < n; i++) {
        cout << (is_good[i] ? ssz(e[i]) : 1) << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}