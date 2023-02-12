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
    vector<pair<int, int>> a(n);
    rep(i, n) {
        int x, s; cin >> x >> s;
        a[i].first = max(0, x - s);
        a[i].second = min(m, x + s);
    }

    vi f(m + 1, INT_MAX);
    f[m] = 0;
    repd(i, m - 1, -1) {
        f[i] = min(f[i], m - i);
        rep(j, n) {
            if (a[j].first <= i + 1 && i + 1 <= a[j].second) {
                f[i] = min(f[i], f[i + 1]);
                break;
            }
            if (i < a[j].first) {
                f[i] = min(f[i], a[j].first - i - 1 + f[min(m, a[j].second + a[j].first - i - 1)]);
            }
        }
    }

    cout << f[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}