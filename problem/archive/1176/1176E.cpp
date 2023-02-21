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
    vector<vi> e(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi color(n, -1);
    function<void(int, int)> dfs = [&] (int u, int p) {
        for (auto& v: e[u]) {
            if (color[v] != -1 || v == p) continue;
            color[v] = color[u] ^ 1;
            dfs(v, u);
        }
    };
    color[0] = 0;
    dfs(0, -1);

    int cnt = 0;
    rep(i, n) {
        if (color[i] == 0) {
            cnt++;
        }
    }

    if (cnt <= n / 2) {
        cout << cnt << endl;
        rep(i, n) {
            if (color[i] == 0) {
                cout << i + 1 << " ";
            }
        }
    } else {
        cout << n - cnt << endl;
        rep(i, n) {
            if (color[i] == 1) {
                cout << i + 1 << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}