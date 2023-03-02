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

ll minxor(const vi& a, int d, int l1, int r1, int l2, int r2) {
    if (l1 >= r1 || l2 >= r2) return LLONG_MAX;
    if (d < 0) return 0;
    int m1 = l1, m2 = l2;
    while (m1 < r1 && (a[m1] >> d & 1) == 0) {
        m1++;
    }
    while (m2 < r2 && (a[m2] >> d & 1) == 0) {
        m2++;
    }
    if (l1 < m1 && l2 < m2 || m1 < r1 && m2 < r2) {
        return min(minxor(a, d - 1, l1, m1, l2, m2), minxor(a, d - 1, m1, r1, m2, r2));
    } else {
        return min(minxor(a, d - 1, l1, m1, m2, r2), minxor(a, d - 1, m1, r1, l2, m2)) + (1ll << d);
    }
}

ll dfs(const vi& a, int d, int l, int r) {
    if (l + 1 >= r || d < 0) return 0;
    int m = l;
    while (m < r && (a[m] >> d & 1) == 0) {
        m++;
    }
    ll ans = dfs(a, d - 1, l, m) + dfs(a, d - 1, m, r);
    if (l < m && m < r) {
        ans += minxor(a, d - 1, l, m, m, r) + (1ll << d);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    sorta(a);
    cout << dfs(a, 30, 0, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}