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
        int p; cin >> p;
        e[p - 1].push_back(i + 1);
    }

    ll ans = 0;
    vi sz(n, 0);
    function<void(int)> dfs = [&] (int u) {
        vi a;
        for (auto v : e[u]) {
            dfs(v);
            sz[u] += sz[v];
            a.push_back(sz[v]);
        }
        int target = (sz[u] + 1) / 2;
        vi f(target + 1, 0);
        f[0] = 1;
        for (int i = 0; i < ssz(a); i++) {
            for (int j = target; j >= a[i]; j--) {
                f[j] += f[j - a[i]];
            }
        }
        ll cur = 0;
        for (int i = target; i > 0; i--) {
            if (f[i]) cur = max(cur, i * 1ll * (sz[u] - i));
        }
        ans += cur;
        sz[u]++;
    };
    dfs(0);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}