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
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        x--;
        e[x].push_back(i + 1);
    }
    vi a(n); in(a);

    ll ans = 0;
    vector<ll> mx(n, 0), cnt(n, 0), sz(n, 0);
    function<void(int)> dfs = [&] (int u) {
        bool is_leaf = true;
        for (auto v : e[u]) {
            is_leaf = false;
            dfs(v);
            mx[u] = max(mx[u], mx[v]);
            cnt[u] += cnt[v];
            sz[u] += sz[v];
        }
        if (is_leaf) {
            mx[u] = a[u];
            cnt[u] = 1;
            sz[u] = a[u];
            return;
        }
        sz[u] += a[u];
        mx[u] = max(mx[u], (sz[u] + cnt[u] - 1) / cnt[u]);
        ans = max(ans, mx[u]);
    };
    dfs(0);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}