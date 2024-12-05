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
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> e(n);
    while (q--) {
        int i, j, x;
        cin >> i >> j >> x;
        i--; j--;
        e[i].emplace_back(j, x);
        e[j].emplace_back(i, x);
        if (i > j) swap(i, j);
    }

    vi ans(n, (1 << 31) - 1);
    for (int i = 0; i < 31; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, x]: e[u]) {
                if (!(x >> i & 1)) {
                    if (ans[u] >> i & 1) ans[u] ^= 1 << i;
                }
            }
        }
        for (int u = 0; u < n; u++) {
            if (ans[u] >> i & 1) {
                ans[u] ^= 1 << i;
                for (auto [v, x]: e[u]) {
                    if (!(ans[v] >> i & 1) && (x >> i & 1)) {
                        ans[u] |= 1 << i;
                        break;
                    }
                }
            }
        }
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}