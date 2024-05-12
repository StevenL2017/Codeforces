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

const int MOD = 998244353;
const int N = 3e5 + 3;
int p[N];

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int precalc() {
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], 2);
    }
}

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

    vi vis(n, -1), cnt(2);
    bool ok = true;
    function<void(int, int, int)> dfs = [&] (int u, int p, int o) {
        if (vis[u] >= 0) {
            if (vis[u] != o) {
                ok = false;
            }
            return;
        }
        vis[u] = o;
        cnt[o]++;
        for (auto v : e[u]) {
            if (v == p) continue;
            dfs(v, u, o ^ 1);
        }
    };

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i] != -1) continue;
        cnt[0] = cnt[1] = 0;
        dfs(i, -1, 0);
        if (!ok) {
            cout << 0 << endl;
            return;
        }
        ans = mul(ans, add(p[cnt[0]], p[cnt[1]]));
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}