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
    int n, m, k;
    cin >> n >> m >> k;
    map<string, int> pattern;
    rep(i, n) {
        string p; cin >> p;
        pattern[p] = i;
    }

    bool ok = true;
    vector<vi> e(n);
    vi deg(n, 0);
    rep(i, m) {
        string s; int x;
        cin >> s >> x;
        x--;

        vector<string> cand;
        function<void(int, string)> dfs = [&] (int idx, string cur) {
            if (idx == k) {
                cand.push_back(cur);
                return;
            }
            dfs(idx + 1, cur + s[idx]);
            dfs(idx + 1, cur + "_");
        };
        dfs(0, "");
        bool ok_cur = false;
        for (auto& c: cand) {
            if (pattern.count(c)) {
                if (pattern[c] == x) {
                    ok_cur = true;
                } else {
                    e[x].push_back(pattern[c]);
                    deg[pattern[c]]++;
                }
            }
        }
        if (!ok_cur) ok = false;
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    vi ans, vis(n, 0);
    queue<int> q;
    rep(i, n) {
        if (deg[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        ans.push_back(u + 1);
        for (auto& v: e[u]) {
            if (vis[v]) continue;
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    if (ssz(ans) < n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}