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
    string s;
    cin >> s;
    vector<set<int>> e(n);
    vi deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (e[u].find(v) == e[u].end()) {
            deg[v]++;
        }
        e[u].insert(v);
    }

    vi vis(n);
    vector<vi> cnt(n, vi(26));
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        vis[u] = 1;
        cnt[u][s[u] - 'a']++;
        for (auto v: e[u]) {
            for (int j = 0; j < 26; j++) {
                cnt[v][j] = max(cnt[v][j], cnt[u][j]);
            }
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << -1 << endl;
            return;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            ans = max(ans, cnt[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}