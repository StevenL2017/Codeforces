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
    vi deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int ans = 0;
    multiset<int> s;
    for (auto x: deg) {
        s.insert(x);
    }
    for (int u = 0; u < n; u++) {
        s.extract(deg[u]);
        multiset<int> adj;
        for (auto v: e[u]) {
            s.extract(deg[v]);
            adj.insert(deg[v]);
        }
        if (!s.empty()) {
            ans = max(ans, deg[u] + *s.rbegin() - 1);
        }
        if (!adj.empty()) {
            ans = max(ans, deg[u] + *adj.rbegin() - 2);
        }
        for (auto v: e[u]) {
            s.insert(deg[v]);
        }
        s.insert(deg[u]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}