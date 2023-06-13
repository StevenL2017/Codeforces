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
    int n; cin >> n;
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }
    vi x(n); in(x);
    for (int i = 0; i < n; i++) x[i]--;

    vector<ll> ans(n, 0), vis(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        vis[x[i]] = 1;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                a[j][k] = min(a[j][k], a[j][x[i]] + a[x[i]][k]);
                if (vis[j] && vis[k]) ans[i] += a[j][k];
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