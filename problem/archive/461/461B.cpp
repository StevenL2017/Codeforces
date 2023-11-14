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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

void solve() {
    int n; cin >> n;
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int p; cin >> p;
        e[p].push_back(i + 1);
    }
    vi a(n); in(a);

    vector<vi> f(n, vi(2, 0));
    function<void(int)> dfs = [&] (int u) {
        f[u][0] = 1;
        f[u][1] = 0;
        for (auto v: e[u]) {
            dfs(v);
            f[u][1] = mul(f[u][1], f[v][0]);
            f[u][1] = add(f[u][1], mul(f[u][0], f[v][1]));
            f[u][0] = mul(f[u][0], f[v][0]);
        }
        if (a[u]) {
            f[u][1] = f[u][0];
        } else {
            f[u][0] = add(f[u][0], f[u][1]);
        }
    };
    dfs(0);
    cout << f[0][1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}