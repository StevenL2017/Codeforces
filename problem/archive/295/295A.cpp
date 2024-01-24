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
    vector<ll> a(n);
    in(a);
    vector<vi> b(m);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        b[i] = {l - 1, r - 1, d};
    }
    vi c(m);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        c[x]++;
        if (y + 1 < m) {
            c[y + 1]--;
        }
    }

    for (int i = 1; i < m; i++) {
        c[i] += c[i - 1];
    }
    vector<ll> diff(n);
    for (int i = 0; i < m; i++) {
        ll d = b[i][2] * 1ll * c[i];
        int l = b[i][0], r = b[i][1];
        diff[l] += d;
        if (r + 1 < n) {
            diff[r + 1] -= d;
        }
    }
    a[0] += diff[0];
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
        a[i] += diff[i];
    }
    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}