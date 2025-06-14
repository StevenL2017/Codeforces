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

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    in(a);
    in(b);

    vector<vi> e(n);
    for (int i = 0; i < n; i++) {
        e[a[i] - 1].push_back(b[i] - 1);
        e[b[i] - 1].push_back(a[i] - 1);
    }

    int ans = 1;
    vi vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        int node = 0, edge = 0, self_loop = 0;
        function<void(int)> dfs = [&] (int u) {
            if (vis[u]) {
                return;
            }
            vis[u] = 1;
            node++;
            for (auto v: e[u]) {
                edge++;
                dfs(v);
                if (v == u) {
                    self_loop = 1;
                }
            }
        };
        dfs(i);
        if (node * 2 != edge) {
            ans = 0;
        } else if (self_loop) {
            ans = ans * 1ll * n % MOD;
        } else {
            ans = ans * 1ll * 2 % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}