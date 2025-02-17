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
    int n, q;
    cin >> n >> q;
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        e[p - 1].push_back(i + 1);
    }

    vi a;
    vector<pair<int, int>> time(n);
    int t = 0;
    function<void(int)> dfs = [&] (int u) {
        a.push_back(u);
        time[u].first = t++;
        sort(begin(e[u]), end(e[u]));
        for (auto v: e[u]) {
            dfs(v);
        }
        time[u].second = t;
    };
    dfs(0);

    while (q--) {
        int u, k;
        cin >> u >> k;
        u--; k--;

        int i = time[u].first + k;
        if (i >= time[u].second) {
            cout << -1 << endl;
        } else {
            cout << a[i] + 1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}