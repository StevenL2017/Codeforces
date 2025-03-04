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
    int n;
    cin >> n;
    vector<double> a(n), v(n);
    in(a);
    in(v);

    auto check = [&] (double mid) -> bool {
        double left = -1e18, right = 1e18;
        for (int i = 0; i < n; i++) {
            left = max(left, a[i] - mid * v[i]);
            right = min(right, a[i] + mid * v[i]);
            if (left > right) return false;
        }
        return true;
    };

    double l = 0, r = 1e18;
    while (r - l > 1e-10) {
        auto mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout.precision(10);
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}