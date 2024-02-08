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

vector<pair<int, int>> intersect(pair<int, int> a1, pair<int, int> b1, pair<int, int> a2, pair<int, int> b2) {
    int r = min(max(a1.first, b1.first), max(a2.first, b2.first));
    int l = max(min(a1.first, b1.first), min(a2.first, b2.first));
    int u = min(max(a1.second, b1.second), max(a2.second, b2.second));
    int d = max(min(a1.second, b1.second), min(a2.second, b2.second));
    if (r <= l || u <= d) return {{0, 0}, {0, 0}};
    return {{l, d}, {r, u}};
}

ll calc(pair<int, int> a, pair<int, int> b) {
    return abs(b.first - a.first) * 1ll * abs(b.second - a.second);
}

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    int x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;

    auto i1 = intersect({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
    auto i2 = intersect({x1, y1}, {x2, y2}, {x5, y5}, {x6, y6});
    auto ii = intersect(i1[0], i1[1], i2[0], i2[1]);
    auto s = calc({x1, y1}, {x2, y2});
    auto s1 = calc(i1[0], i1[1]);
    auto s2 = calc(i2[0], i2[1]);
    auto si = calc(ii[0], ii[1]);

    if (s - s1 - s2 + si > 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}