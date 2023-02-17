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
    int n; cin >> n;
    vi a(3), b(3); in(a); in(b);

    auto mn_win = [&] (vi x, vi y) {
        int ans = 0;
        rep(i, 3) {
            rep(j, 3) {
                if (i == j) continue;
                rep(k, 3) {
                    if (i == k || j == k) continue;
                    int cur = 0;
                    vi xx = x, yy = y;
                    for (int c: vi{i, j, k}) {
                        int mn = min(xx[c], yy[(c - 1 + 3) % 3]);
                        cur += mn;
                        xx[c] -= mn;
                        yy[(c - 1 + 3) % 3] -= mn;
                        mn = min(xx[c], yy[c]);
                        cur += mn;
                        xx[c] -= mn;
                        yy[c] -= mn;
                    }
                    ans = max(ans, cur);
                }
            }
        }
        return n - ans;
    };

    auto mx_win = [&] (vi x, vi y) {
        int ans = 0;
        rep(i, 3) {
            int j = (i + 1) % 3;
            ans += min(x[i], y[j]);
        }
        return ans;
    };

    vi ans = {mn_win(a, b), mx_win(a, b)};
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}