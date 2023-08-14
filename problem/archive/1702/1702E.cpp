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
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<set<int>> d(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        d[a[i].first].insert(i);
        d[a[i].second].insert(i);
    }

    for (int i = 1; i <= n; i++) {
        if (ssz(d[i]) != 2) {
            cout << "NO\n";
            return;
        }
    }

    vi vis(n, -1);
    bool ok = true;
    function<void(int, int)> dfs = [&] (int i, int c) {
        if (vis[i] != -1) {
            if (vis[i] != c) ok = false;
            return;
        }
        vis[i] = c;
        auto [x, y] = a[i];
        for (auto ni : d[x]) {
            if (ni == i) continue;
            dfs(ni, c ^ 1);
        }
        for (auto ni : d[y]) {
            if (ni == i) continue;
            dfs(ni, c ^ 1);
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) dfs(i, 0);
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}