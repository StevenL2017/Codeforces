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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vector<vi> e1(n), e2(n);
    rep(i, n - 1) {
        int p; cin >> p;
        e1[p - 1].push_back(i + 1);
    }
    rep(i, n - 1) {
        int p; cin >> p;
        e2[p - 1].push_back(i + 1);
    }

    int t = 1;
    vi st(n), ft(n);
    function<void(int)> dfs1 = [&] (int u) {
        st[u] = t++;
        for (auto& v: e2[u]) {
            dfs1(v);
        }
        ft[u] = t;
    };
    dfs1(0);

    function<int(int, int)> is_ancestor = [&] (int u, int v) -> int {
        return st[u] <= st[v] && ft[v] <= ft[u];
    };

    int ans = 0;
    set<pair<int, int>> s;
    function<void(int)> dfs2 = [&] (int u) {
        auto it = s.lower_bound({st[u], u});
        int flag;
        if (it != s.end() && is_ancestor(u, it->second)) {
            flag = -2;
        }
        else if (it != s.begin()) {
            --it;
            if (is_ancestor(it->second, u)) {
                flag = it->second;
                s.erase(it);
            } else {
                flag = -1;
            }
        }
        else {
            flag = -1;
        }
        if (flag != -2) s.insert({st[u], u});
        ans = max(ans, ssz(s));
        for (auto& v: e1[u]) {
            dfs2(v);
        }
        if (flag != -2) {
            s.erase({st[u], u});
            if (flag != -1) s.insert({st[flag], flag});
        }
    };
    dfs2(0);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}