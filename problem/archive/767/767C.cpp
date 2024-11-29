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
    vi a(n);
    int root = -1, tot = 0;
    for (int i = 0; i < n; i++) {
        int p, t;
        cin >> p >> t;
        if (p) {
            e[p - 1].push_back(i);
        } else {
            root = i;
        }
        a[i] = t;
        tot += t;
    }

    if (tot % 3) {
        cout << -1 << endl;
        return;
    }

    tot /= 3;
    vi ans;
    function<void(int)> dfs = [&] (int u) {
        for (auto v: e[u]) {
            dfs(v);
            a[u] += a[v];
        }
        if (u != root && a[u] == tot) {
            ans.push_back(u + 1);
            a[u] = 0;
        }
    };
    dfs(root);

    if (ssz(ans) > 1) {
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}