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
    vi a(n);
    in(a);
    vector<vi> e(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        e[p].push_back(i);
    }

    int k = 0;
    vi f(n);
    function<void(int)> dfs = [&] (int u) {
        if (e[u].empty()) {
            k++;
            f[u] = 1;
            return;
        }
        if (a[u]) f[u] = 1e9;
        for (auto v: e[u]) {
            dfs(v);
            if (a[u]) {
                f[u] = min(f[u], f[v]);
            } else {
                f[u] += f[v];
            }
        }
    };
    dfs(0);
    cout << k - f[0] + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}