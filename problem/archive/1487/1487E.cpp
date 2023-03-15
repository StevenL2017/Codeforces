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
    vi n(4);
    rep(i, 4) cin >> n[i];
    vector<vi> a(4);
    rep(i, 4) {
        a[i].resize(n[i]);
        in(a[i]);
    }
    vector<vector<vi>> e(3);
    rep(i, 3) {
        e[i].resize(n[i + 1]);
        int m; cin >> m;
        rep(j, m) {
            int u, v; cin >> u >> v;
            u--; v--;
            e[i][v].push_back(u);
        }
    }

    vector<vi> f(4);
    f[0] = a[0];
    rep(i, 3) {
        f[i + 1].resize(n[i + 1]);
        multiset<int> s;
        rep(j, n[i]) {
            s.insert(f[i][j]);
        }
        rep(j, n[i + 1]) {
            for (auto& v: e[i][j]) {
                s.erase(s.find(f[i][v]));
            }
            if (s.empty()) {
                f[i + 1][j] = (int)(4e8 + 3);
            } else {
                f[i + 1][j] = *s.begin() + a[i + 1][j];
            }
            for (auto& v: e[i][j]) {
                s.insert(f[i][v]);
            }
        }
    }

    int ans = *min_element(f[3].begin(), f[3].end());
    cout << (ans < 4e8 + 3 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}