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
    vector<char> d(n); in(d);

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; });

    vi ans(n, INT_MAX);
    vi left_odd, left_even, right_odd, right_even;
    rep(i0, n) {
        int i = idx[i0];
        if (d[i] == 'R') {
            if (a[i] & 1) {
                right_odd.push_back(i);
            } else {
                right_even.push_back(i);
            }
        } else {
            if (a[i] & 1) {
                if (!right_odd.empty()) {
                    int j = right_odd.back();
                    right_odd.pop_back();
                    int t = (a[i] - a[j]) / 2;
                    ans[i] = min(ans[i], t);
                    ans[j] = min(ans[j], t);
                } else {
                    left_odd.push_back(i);
                }
            } else {
                if (!right_even.empty()) {
                    int j = right_even.back();
                    right_even.pop_back();
                    int t = (a[i] - a[j]) / 2;
                    ans[i] = min(ans[i], t);
                    ans[j] = min(ans[j], t);
                } else {
                    left_even.push_back(i);
                }
            }
        }
    }

    reverse(left_odd.begin(), left_odd.end());
    reverse(left_even.begin(), left_even.end());
    auto check1 = [&] (vi& b, int w) {
        while (ssz(b) > 1) {
            int i = b.back();
            b.pop_back();
            int j = b.back();
            b.pop_back();
            int t = abs(a[i] - a[j]) / 2;
            if (w == 0) {
                t += a[i];
            } else {
                t += w - a[i];
            }
            ans[i] = min(ans[i], t);
            ans[j] = min(ans[j], t);
        }
    };
    check1(left_odd, 0);
    check1(left_even, 0);
    check1(right_odd, m);
    check1(right_even, m);

    auto check2 = [&] (vi& l, vi& r) {
        while (!l.empty() && !r.empty()) {
            int i = l.back();
            l.pop_back();
            int j = r.back();
            r.pop_back();
            int t = abs(a[i] - a[j]) / 2 + a[i] + m - a[j];
            ans[i] = min(ans[i], t);
            ans[j] = min(ans[j], t);
        }
    };
    check2(left_odd, right_odd);
    check2(left_even, right_even);

    rep(i, n) {
        if (ans[i] == INT_MAX) {
            ans[i] = -1;
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