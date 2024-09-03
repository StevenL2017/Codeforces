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
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vi a(n);
    in(a);

    vi ans, cnt(n, 1), vis(n);
    queue<int> q;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == a[i]) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u + 1);
        for (auto v: e[u]) {
            if (cnt[v] == a[u]) {
                cnt[v]++;
            }
            if (cnt[v] == a[v] && !vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
            if (cnt[v] > a[v]) {
                ok = false;
            }
        }
    }

    if (ssz(ans) < n || !ok) {
        cout << -1 << endl;
    } else {
        out(ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}