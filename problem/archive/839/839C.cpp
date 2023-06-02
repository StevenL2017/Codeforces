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
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    function<long double(int, int)> dfs = [&] (int u, int p) -> long double {
        long double ans = 0.0;
        for (auto v : e[u]) {
            if (v == p) continue;
            ans += dfs(v, u);
        }
        auto sz = ssz(e[u]) - (p != -1);
        return (sz > 0 ? ans / sz + 1 : 0);
    };

    cout.precision(20);
    cout << dfs(0, -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}