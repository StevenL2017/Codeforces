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
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);

    vector<pair<vi, vi>> c;
    int i = 0;
    while (i < n && a[i] != 0) {
        i++;
    }
    while (i < n) {
        int i0 = i++;
        pair<vi, vi> cur;
        while (i < n && a[i] != 0) {
            if (a[i] < 0) {
                cur.first.push_back(-a[i]);
            } else {
                cur.second.push_back(a[i]);
            }
            i++;
        }
        sort(begin(cur.first), end(cur.first));
        sort(begin(cur.second), end(cur.second));
        c.push_back(cur);
    }

    n = ssz(c);
    vi f(m + 1, -2e9);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        auto [c1, c2] = c[i];
        vi g = f;
        for (int j = 0; j <= m; j++) {
            if (f[j] == -2e9) {
                continue;
            }
            if (j < i + 1) {
                int k1 = upper_bound(begin(c1), end(c1), i + 1 - j) - begin(c1);
                int k2 = upper_bound(begin(c2), end(c2), j) - begin(c2);
                g[j] = max(g[j], f[j] + k1 + k2);
            }
            if (j < m) {
                int k1 = upper_bound(begin(c1), end(c1), i - j) - begin(c1);
                int k2 = upper_bound(begin(c2), end(c2), j + 1) - begin(c2);
                g[j + 1] = max(g[j + 1], f[j] + k1 + k2);
            }
        }
        f = g;
    }

    cout << *max_element(begin(f), end(f)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}