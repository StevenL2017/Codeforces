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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vector<long double> a(n); in(a);

    auto calc = [&] (vector<long double>& a) -> long double {
        long double mx = 0, cur = 0;
        for (auto x: a) {
            cur += x;
            if (cur > mx) mx = cur;
            if (cur < 0) cur = 0;
        }
        return mx;
    };

    auto check = [&] (long double x, long double& vp, long double& vn) {
        vector<long double> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] - x;
        }
        vp = calc(b);
        for (int i = 0; i < n; i++) {
            b[i] *= -1;
        }
        vn = calc(b);
    };

    long double l = *min_element(a.begin(), a.end());
    long double r = *max_element(a.begin(), a.end());
    for (int i = 0; i < 50; i++) {
        long double mid = (l + r) / 2, vp, vn;
        check(mid, vp, vn);
        if (vp >= vn) {
            l = mid;
        } else {
            r = mid;
        }
    }

    long double mid = (l + r) / 2, vp, vn;
    check(mid, vp, vn);

    cout.precision(10);
    cout << max(vp, vn) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}