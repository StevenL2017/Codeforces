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
    vector<vi> e(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n - 1; i++) {
        int p, x, y;
        cin >> p >> x >> y;
        int u = p - 1, v = i + 1;
        e[u].push_back(v);
        a[v] = {x, y};
    }

    vi ans(n - 1);
    vector<ll> pre(1);
    function<void(int, ll)> dfs = [&] (int u, ll s) {
        if (u > 0) ans[u - 1] = upper_bound(begin(pre), end(pre), s) - begin(pre) - 1;
        for (auto v: e[u]) {
            pre.emplace_back(pre.back() + a[v].second);
            dfs(v, s + a[v].first);
            pre.pop_back();
        }
    };
    dfs(0, 0);
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}