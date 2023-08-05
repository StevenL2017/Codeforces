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
    ll r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    ll s = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    ll d = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d * d == s) {
        cout << (d + 2 * r - 1) / (2 * r) << endl;
        return;
    }
    auto k = (d + 1 + 2 * r - 1) / (2 * r);
    k += (int)(d - k * (2 * r) > r);

    cout << k << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}