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
    vector<vi> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi cnt(n, 0);
    int mn = n;
    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        int sz = 1, mx = 0;
        for (auto& v: e[u]) {
            if (v == p) continue;
            auto nxt = dfs(v, u);
            sz += nxt;
            mx = max(mx, nxt);
        }
        mx = max(mx, n - sz);
        cnt[u] = mx;
        mn = min(mn, mx);
        return sz;
    };
    dfs(0, -1);

    vi c;
    rep(i, n) {
        if (cnt[i] == mn) c.push_back(i);
    }

    if (ssz(c) == 1) {
        cout << c[0] + 1 << " " << e[c[0]][0] + 1 << endl;
        cout << c[0] + 1 << " " << e[c[0]][0] + 1 << endl;
    } else {
        int c1 = c[0], c2 = c[1], c3 = 0;
        for (auto& v: e[c2]) {
            if (v != c1) {
                c3 = v;
                break;
            }
        }
        cout << c2 + 1 << " " << c3 + 1 << endl;
        cout << c1 + 1 << " " << c3 + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}