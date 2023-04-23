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

int query(set<int> s) {
    cout << "? " << ssz(s) << " ";
    for (auto& u: s) cout << u << " ";
    cout << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    vector<vi> e(n + 1);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    set<int> s;
    repa(i, 1, n + 1) {
        s.insert(i);
    }
    auto target = query(s);

    vi tour;
    function<void(int, int)> dfs = [&] (int u, int p) {
        tour.push_back(u);
        for (auto& v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
            tour.push_back(u);
        }
    };
    dfs(1, 0);

    int m = ssz(tour);
    int left = 0, right = m - 1;
    while (left < right - 1) {
        auto mid = (left + right) / 2;
        set<int> q;
        repa(i, left, mid + 1) {
            q.insert(tour[i]);
        }
        auto cur = query(q);
        if (cur == target) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << "! " << tour[left] << " " << tour[right] << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}