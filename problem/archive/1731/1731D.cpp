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
    vector<vi> a(n, vi(m));
    rep(i, n) in(a[i]);

    auto check = [&] (int x) -> bool {
        vector<vi> b(n, vi(m, 0));
        rep(i, n) {
            rep(j, m) {
                if (a[i][j] >= x) b[i][j] = 1;
            }
        }

        vector<vi> pre(n + 1, vi(m + 1, 0));
        rep(i, n) {
            rep(j, m) {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + b[i][j];
            }
        }

        repa(i, x, n + 1) {
            repa(j, x, m + 1) {
                if (pre[i][j] - pre[i - x][j] - pre[i][j - x] + pre[i - x][j - x] == x * x) return true;
            }
        }
        return false;
    };

    int left = 1, right = n, ans = left;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
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