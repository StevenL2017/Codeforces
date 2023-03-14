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
    string s; cin >> s;

    int n = ssz(s);
    vector<set<int>> e(26);
    rep(i, n - 1) {
        int u = s[i] - 'a';
        int v = s[i + 1] - 'a';
        e[u].insert(v);
        e[v].insert(u);
    }

    string ans;
    vi vis(26, 0);
    function<bool(int, int)> dfs = [&] (int u, int p) -> bool {
        if (vis[u]) return false;
        if (ssz(e[u]) > 2) return false;
        vis[u] = 1;
        ans += (char)(u + 'a');
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
        return true;
    };

    rep(i, 26) {
        if (!vis[i]) {
            if (ssz(e[i]) <= 1) {
                bool ok = dfs(i, -1);
                if (!ok) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    if (ssz(ans) < 26) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}