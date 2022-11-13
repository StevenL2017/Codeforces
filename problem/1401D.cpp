#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int m; cin >> m;
    vi p(m); in(p);

    vector<ll> f(n - 1, 0);
    function<int(int, int)> dfs = [&] (int node, int fa) -> int {
        int cnt = 1;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            cnt += dfs(nxt, node);
        }
        if (node != 0) {
            f[node - 1] = 1ll * (n - cnt) * cnt;
        }
        return cnt;
    };
    dfs(0, -1);

    sorta(f), sorta(p);
    ll ans = 0;
    if (n - 1 >= m) {
        rep(i, n - 1 - m) {
            ans += f[i];
            ans %= MOD;
        }
        rep(i, m) {
            ans += f[i + n - 1 - m] * p[i];
            ans %= MOD;
        }
    } else {
        rep(i, n - 2) {
            ans += f[i] * p[i];
            ans %= MOD;
        }
        ll temp = f[n - 2];
        repa(i, n - 2, m) {
            temp *= p[i];
            temp %= MOD;
        }
        ans += temp;
        ans %= MOD;
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