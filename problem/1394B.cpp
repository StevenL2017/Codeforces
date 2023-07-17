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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e[u].emplace_back(w, v);
    }

    vector<vi> id(10, vi(10, 0));
    int c = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < i; j++) {
            id[i][j] = c++;
        }
    }

    vector<vector<pair<int, int>>> a(n);
    for (int u = 0; u < n; u++) {
        sort(e[u].begin(), e[u].end());
        int s = ssz(e[u]);
        for (int j = 0; j < s; j++) {
            int v = e[u][j].second;
            a[v].emplace_back(s, j);
        }
    }

    vector<ll> can(c, (1ll << c) - 1);
    for (int u = 0; u < n; u++) {
        vi cnt(c, 0);
        for (auto [s, j] : a[u]) {
            cnt[id[s][j]]++;
        }
        for (int i = 0; i < c; i++) {
            if (!cnt[i]) continue;
            if (cnt[i] > 1) {
                can[i] = 0;
            } else {
                for (int j = 0; j < c; j++) {
                    if (i != j && cnt[j]) {
                        can[i] &= ~(1ll << j);
                    }
                }
            }
        }
    }

    int ans = 0;
    function<void(int, ll)> dfs = [&] (int i, ll mask) {
        if (i > k) {
            ans++;
            return;
        }
        for (int j = 0; j < i; j++) {
            if (can[id[i][j]] && (mask >> id[i][j] & 1)) {
                dfs(i + 1, mask & can[id[i][j]]);
            }
        }
    };
    dfs(1, (1ll << c) - 1);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}