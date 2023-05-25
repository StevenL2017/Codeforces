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
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        mp[make_pair(min(u, v), max(u, v))] = i + 1;
    }

    vi ans;
    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        map<int, int> cnt;
        for (auto v : e[u]) {
            if (v == p) continue;
            int nxt = dfs(v, u);
            cnt[nxt]++;
            if (cnt[-1] || cnt[2] > 1 || cnt[1] > 2 || (cnt[2] && cnt[1])) {
                return -1;
            }
        }
        if (cnt[2] == 1 || cnt[1] == 2) {
            if (p != -1) ans.push_back(mp[{min(u, p), max(u, p)}]);
            return 0;
        }
        else if (cnt[1] == 1) {
            return 2;
        }
        else {
            return 1;
        }
    };

    if (dfs(0, -1) != 0) {
        cout << -1 << endl;
        return;
    }
    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}