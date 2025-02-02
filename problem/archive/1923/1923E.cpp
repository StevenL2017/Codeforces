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
    vi a(n);
    in(a);
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ll ans = 0;
    vector<map<int, int>> cnt(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        int bst = -1;
        for (auto v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (bst == -1 || ssz(cnt[v]) > ssz(cnt[bst])) {
                bst = v;
            }
        }
        for (auto v: e[u]) {
            if (v == p || v == bst) continue;
            for (auto [k, c]: cnt[v]) {
                if (k != a[u]) ans += c * 1ll * cnt[bst][k];
                cnt[bst][k] += c;
            }
        }
        if (bst != -1) swap(cnt[bst], cnt[u]);
        ans += cnt[u][a[u]];
        cnt[u][a[u]] = 1;
    };
    dfs(0, -1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}