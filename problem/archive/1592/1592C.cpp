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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int xor_ = 0;
    for (auto x: a) {
        xor_ ^= x;
    }

    if (xor_ == 0) {
        cout << "YES" << endl;
        return;
    }

    int cnt = 0;
    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        int cur = a[u];
        for (auto v: e[u]) {
            if (v == p) {
                continue;
            }
            cur ^= dfs(v, u);
        }
        if (cur == xor_) {
            cnt++;
            return 0;
        }
        return cur;
    };
    dfs(0, -1);

    cout << (cnt > 1 && k >= 3 ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}