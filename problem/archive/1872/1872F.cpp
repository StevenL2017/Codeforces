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
    vi a(n), c(n);
    in(a);
    in(c);

    vector<vi> e(n);
    vi deg(n);
    for (int i = 0; i < n; i++) {
        e[i].push_back(a[i] - 1);
        deg[a[i] - 1]++;
    }

    vi ans;
    queue<int> q;
    vi vis(n);
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        ans.push_back(u + 1);
        for (auto v: e[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        int mn = c[i], idx = i;
        int u = a[i] - 1;
        while (u != i) {
            vis[u] = 1;
            if (c[u] < mn) {
                mn = c[u];
                idx = u;
            }
            u = a[u] - 1;
        }
        u = a[idx] - 1;
        while (u != idx) {
            ans.push_back(u + 1);
            u = a[u] - 1;
        }
        ans.push_back(idx + 1);
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}