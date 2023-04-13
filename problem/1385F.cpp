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
    int n, k; cin >> n >> k;
    vector<set<int>> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].insert(v);
        e[v].insert(u);
    }

    vector<set<int>> leaves(n);
    rep(i, n) {
        if (ssz(e[i]) == 1) {
            leaves[*e[i].begin()].insert(i);
        }
    }

    set<pair<int, int>> s;
    rep(i, n) {
        s.emplace(-ssz(leaves[i]), i);
    }

    int ans = 0;
    while (true) {
        auto [cnt, u] = *s.begin();
        if (-cnt < k) {
            break;
        }
        rep(i, k) {
            auto v = *leaves[u].begin();
            e[u].erase(v);
            e[v].erase(u);
            leaves[u].erase(v);
            s.erase({-ssz(leaves[v]), v});
        }
        s.erase({cnt, u});
        if (ssz(e[u]) == 1) {
            auto f = *e[u].begin();
            s.erase({-ssz(leaves[f]), f});
            leaves[f].insert(u);
            s.emplace(-ssz(leaves[f]), f);
        } else {
            s.emplace(-ssz(leaves[u]), u);
        }
        ans++;
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