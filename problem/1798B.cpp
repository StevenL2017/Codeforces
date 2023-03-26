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
    int m; cin >> m;
    vector<vi> a(m);
    rep(i, m) {
        int n; cin >> n;
        a[i].resize(n); in(a[i]);
    }

    vi ans(m, -1);
    ans[m - 1] = a[m - 1][0];
    set<int> vis;
    repd(i, m - 1, -1) {
        if (i < m - 1) {
            for (auto& x: a[i]) {
                if (vis.count(x)) {
                    continue;
                }
                ans[i] = x;
                break;
            }
            if (ans[i] == -1) {
                cout << -1 << endl;
                return;
            }
        }
        for (auto& x: a[i]) {
            vis.insert(x);
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}