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
    vi a(n); in(a);

    set<int> vis;
    rep(i, n) {
        vis.insert(a[i]);
    }

    vi ans;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    rep(i, n) {
        if (!vis.count(a[i] - 1)) {
            q.emplace(1, a[i] - 1, a[i]);
            vis.insert(a[i] - 1);
        }
        if (!vis.count(a[i] + 1)) {
            q.emplace(1, a[i] + 1, a[i]);
            vis.insert(a[i] + 1);
        }
    }

    ll tot = 0;
    while (ssz(ans) < m) {
        auto [d, y, x] = q.top();
        q.pop();
        tot += d;
        ans.push_back(y);
        d++;
        if (!vis.count(x - d)) {
            q.emplace(d, x - d, x);
            vis.insert(x - d);
        }
        if (!vis.count(x + d)) {
            q.emplace(d, x + d, x);
            vis.insert(x + d);
        }
    }

    cout << tot << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}