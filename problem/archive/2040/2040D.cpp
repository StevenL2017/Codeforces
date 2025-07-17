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
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi q, vis(n), ans(n);
    int l = 2, r = 2 * n, op = 0;
    q.push_back(0);
    vis[0] = 1;
    ans[0] = l;
    l += 2;
    op ^= 1;
    while (!q.empty()) {
        vi nq;
        for (auto u: q) {
            for (auto v: e[u]) {
                if (vis[v]) {
                    continue;
                }
                nq.push_back(v);
                vis[v] = 1;
                if (op) {
                    ans[v] = r;
                    r -= 2;
                } else {
                    ans[v] = l;
                    l += 2;
                }
                if (abs(ans[v] - ans[u]) == 2) {
                    ans[v] = ans[u] - 1;
                }
            }
        }
        op ^= 1;
        q = nq;
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}