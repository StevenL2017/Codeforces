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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> robbers(n), lights(m);
    rep(i, n) cin >> robbers[i].first >> robbers[i].second;
    rep(i, m) cin >> lights[i].first >> lights[i].second;

    vi diff(1e6 + 1, 0);
    rep(i, n) {
        auto a = robbers[i].first, b = robbers[i].second;
        rep(j, m) {
            auto c = lights[j].first, d = lights[j].second;
            if (a > c) continue;
            diff[c - a] = max(diff[c - a], max(0, d - b + 1));
        }
    }

    repd(i, 1e6, -1) {
        diff[i] = max(diff[i], diff[i + 1]);
    }

    int ans = INT_MAX;
    rep(x, 1e6 + 1) {
        ans = min(ans, x + diff[x]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}