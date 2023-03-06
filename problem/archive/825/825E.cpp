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
    int n, m; cin >> n >> m;
    vector<vi> e(n);
    vi deg(n, 0);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[v].push_back(u);
        deg[u]++;
    }
    
    set<pair<int, int>> s;
    rep(i, n) {
        s.emplace(deg[i], -i);
    }

    vi ans(n, 0);
    int idx = n;
    while (!s.empty()) {
        auto mn = *s.begin();
        s.erase(mn);
        int u = -mn.second;
        for (auto& v: e[u]) {
            s.erase({deg[v], -v});
            deg[v]--;
            s.insert({deg[v], -v});
        }
        ans[u] = idx--;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}