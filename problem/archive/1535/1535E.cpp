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

const int K = 20;

void solve() {
    int q; cin >> q;
    vi a(q + 1, 0), c(q + 1, 0);
    cin >> a[0] >> c[0];

    vector<vi> f(q + 1, vi(K, 0));
    rep(j, K) {
        f[0][j] = 0;
    }

    repa(i, 1, q + 1) {
        int op; cin >> op;
        if (op == 1) {
            int p;
            cin >> p >> a[i] >> c[i];

            f[i][0] = p;
            repa(j, 1, K) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
        } else {
            int v, w; cin >> v >> w;

            vector<ll> ans(2, 0);
            while (w > 0 && a[v] > 0) {
                int u = v;
                repd(j, K - 1, -1) {
                    if (a[f[u][j]] > 0) {
                        u = f[u][j];
                    }
                }
                auto mn = min(w, a[u]);
                w -= mn;
                a[u] -= mn;
                ans[0] += mn;
                ans[1] += mn * 1ll * c[u];
            }

            out(ans);
            cout.flush();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}