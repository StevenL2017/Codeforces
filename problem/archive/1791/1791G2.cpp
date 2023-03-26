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
    int n, c; cin >> n >> c;
    vi a(n); in(a);

    vector<pair<int, int>> b(n);
    rep(i, n) {
        b[i] = {min(a[i] + i + 1, a[i] + n - i), a[i] + i + 1};
    }
    sorta(b);

    vector<ll> pre(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i] + b[i].first;
    }

    int ans = 0;
    rep(i, n) {
        int nc = c - b[i].second;
        int left = 0, right = n, mx = left;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            auto cost = pre[mid];
            auto cur = mid + 1;
            if (mid > i) {
                cost -= b[i].first;
                cur--;
            }
            if (cost <= nc) {
                left = mid + 1;
                mx = max(mx, cur);
            } else {
                right = mid - 1;
            }
        }
        ans = max(ans, mx);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}