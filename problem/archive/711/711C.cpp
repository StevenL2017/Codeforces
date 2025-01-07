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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    in(a);
    vector<vi> w(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(w[i]);
    }

    vector<vector<ll>> f(m + 1, vector<ll>(k + 1, 1e12));
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) {
            f[i][1] = w[0][i - 1];
        }
    } else {
        f[a[0]][1] = 0;
    }
    
    for (int i = 1; i < n; i++) {
        vector<vector<ll>> g(m + 1, vector<ll>(k + 1, 1e12));
        for (int x = 1; x <= m; x++) {
            for (int j = 0; j <= k; j++) {
                if (f[x][j] >= 1e12) {
                    continue;
                }
                if (a[i] == 0) {
                    for (int c = 1; c <= m; c++) {
                        if (c != x && j == k) {
                            continue;
                        }
                        g[c][j + (c != x)] = min(g[c][j + (c != x)], f[x][j] + w[i][c - 1]);
                    }
                } else {
                    if (a[i] != x && j == k) {
                        continue;
                    }
                    g[a[i]][j + (a[i] != x)] = min(g[a[i]][j + (a[i] != x)], f[x][j]);
                }
            }
        }
        f = g;
    }

    ll ans = 1e12;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, f[i][k]);
    }

    cout << (ans < 1e12 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}