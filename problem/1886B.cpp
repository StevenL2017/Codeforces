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
    int px, py;
    cin >> px >> py;
    int ax, ay;
    cin >> ax >> ay;
    int bx, by;
    cin >> bx >> by;

    int pa = (px - ax) * (px - ax) + (py - ay) * (py - ay);
    int pb = (px - bx) * (px - bx) + (py - by) * (py - by);
    int ab = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    int a = ax * ax + ay * ay;
    int b = bx * bx + by * by;

    auto check = [&] (long double r) -> bool {
        auto x = r * r;
        if (a <= x && pa <= x) return true;
        if (b <= x && pb <= x) return true;
        if (ab <= 4 * x && ((a <= x && pb <= x) || (b <= x && pa <= x))) return true;
        return false;
    };

    long double left = 0, right = 1e9;
    long double ans = right;
    while (left + 1e-8 <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid;
            ans = mid;
        } else {
            left = mid;
        }
    }

    cout.precision(16);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}