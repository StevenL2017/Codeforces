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

const int primes[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int fact[54];

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    for (int x = 1; x < 54; x++) {
        int tot = 0;
        for (int i = 0; i < 16; i++) {
            if (x % primes[i] == 0) {
                tot |= (1 << i);
            }
        }
        fact[x] = tot;
    }

    int m = (1 << 16);
    vector<vi> f(n + 1, vi(m)), g(n + 1, vi(m));
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < m; mask++) {
            f[i + 1][mask] = 2e9;
            for (int j = 1; j < 54; j++) {
                if ((~mask) & fact[j]) continue;
                auto v = f[i][mask ^ fact[j]] + abs(a[i] - j);
                if (v < f[i + 1][mask]) {
                    f[i + 1][mask] = v;
                    g[i + 1][mask] = j;

                }
            }
        }
    }

    int tot = 2e9, mask = 0;
    for (int s = 0; s < m; s++) {
        if (f[n][s] < tot) {
            tot = f[n][s];
            mask = s;
        }
    }

    vi ans(n);
    for (int i = n; i > 0; i--) {
        ans[i - 1] = g[i][mask];
        mask ^= fact[g[i][mask]];
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