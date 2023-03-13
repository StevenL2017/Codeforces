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
    vi e(n, 0);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u] |= 1 << v;
        e[v] |= 1 << u;
    }

    vi f(1 << n, 0);
    rep(i, n) {
        f[1 << i] |= 1 << i;
    }
    repa(mask, 1, 1 << n) {
        int adj = 0;
        rep(i, n) {
            if (mask >> i & 1) {
                adj |= e[i];
            }
        }
        int lo = __builtin_ctz(mask);
        if (adj == (1 << n) - 1 && (e[lo] & f[mask])) {
            int nxt = lo, s = mask;
            vi cyc;
            while (s != (1 << lo)) {
                int t = __builtin_ctz(e[nxt] & f[s]);
                cyc.push_back(t);
                s ^= 1 << t;
                nxt = t;
            }
            cyc.push_back(lo);

            vi ans(n, 0);
            queue<int> q;
            rep(i, ssz(cyc)) {
                ans[cyc[i]] = cyc[(i + 1) % ssz(cyc)] + 1;
                q.push(cyc[i]);
            }
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                rep(i, n) {
                    if ((e[u] >> i & 1) && !ans[i]) {
                        ans[i] = u + 1;
                        q.push(i);
                    }
                }
            }
            cout << "Yes\n";
            out(ans);
            return;
        }

        int cur = 0;
        rep(i, n) {
            if (f[mask] >> i & 1) {
                cur |= e[i];
            }
        }
        repa(i, lo, n) {
            if ((~mask & cur) >> i & 1) {
                f[mask | (1 << i)] |= 1 << i;
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}