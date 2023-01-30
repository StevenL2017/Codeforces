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
    int n; cin >> n;
    vi a(n); in(a);

    vector<vi> e(n + 1);
    repa(u, 1, n + 1) {
        int v = u + a[u - 1];
        if (v < 1 || v > n) v = 0;
        e[v].push_back(u);
    }

    vi sz(n + 1, 0);
    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        int cnt = 1;
        for (auto& v: e[u]) {
            if (v == p) continue;
            cnt += dfs(v, u);
        }
        sz[u] = cnt;
        return cnt;
    };
    dfs(0, -1);

    vi vis(n + 1, 0);
    int v = 1, ok = 1;
    while (v >= 1 && v <= n) {
        if (vis[v]) {
            ok = 0;
            break;
        }
        vis[v] = 1;
        v += a[v - 1];
    }

    ll ans = 0;
    int valid = sz[0] - 1;
    if (ok) {
        repa(u, 1, n + 1) {
            if (!vis[u]) {
                ans += 2 * n + 1;
            } else {
                ans += valid - sz[u] + n + 1;
            }
        }
    } else {
        repa(u, 1, n + 1) {
            if (vis[u]) {
                ans += valid + n + 1;
            }
        }
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