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

const double EPS = 1e-2;

double fgcd(double x, double y) {
    return fabs(y) < EPS ? fabs(x) : fgcd(y, fmod(x, y));
}

void solve() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    auto a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    auto b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    auto c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    auto s = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1);
    auto r = 0.25 * a * b * c / s;
    auto angle_a = asin(2 * s / (b * c));
    auto angle_b = asin(2 * s / (a * c));
    auto pi = atan2(0, -1);
    auto t = fgcd(pi, fgcd(angle_a, angle_b));
    auto ans = 0.5 * pi * r * r * sin(2 * t) / t;

    cout.precision(8);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}