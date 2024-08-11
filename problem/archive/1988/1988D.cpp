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
    int n;
    cin >> n;
    vector<ll> a(n);
    in(a);
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<vector<ll>> f(n, vector<ll>(24, 9e18));
    function<void(int, int)> dfs = [&] (int u, int p) {
        for (int j = 1; j < 23; j++) {
            f[u][j] = j * a[u];
        }
        for (auto v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
            ll mn = 9e18;
            vector<ll> suf(24, 9e18);
            for (int j = 22; j >= 0; j--) {
                suf[j] = min(suf[j + 1], f[v][j]);
            }
            for (int j = 1; j < 23; j++) {
                f[u][j] += min(mn, suf[j + 1]);
                mn = min(mn, f[v][j]);
            }
        }
    };
    dfs(0, -1);

    cout << *min_element(f[0].begin(), f[0].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}