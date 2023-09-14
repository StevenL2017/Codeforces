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
    vector<double> a(n), b(n);
    in(a); in(b);

    auto calc = [&] (double x) -> double {
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, b[i] + abs(x - a[i]));
        }
        return ans;
    };

    auto minimize = [&] (double left, double right) -> double {
        while (right - left >= 1e-6) {
            auto diff = right - left;
            auto mid1 = left + diff / 3;
            auto mid2 = left + 2 * diff / 3;
            if (calc(mid1) > calc(mid2)) {
                left = mid1;
            } else {
                right = mid2;
            }
        }
        return left;
    };

    double mn = double(*min_element(a.begin(), a.end()));
    double mx = double(*max_element(a.begin(), a.end()));
    cout.precision(8);
    cout << minimize(mn, mx) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}