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
    int W, H; cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h; cin >> w >> h;

    int w0 = x2 - x1, h0 = y2 - y1;
    if (w0 + w > W && h0 + h > H) {
        cout << -1 << endl;
        return;
    }

    auto calc = [&] (int x, int y) -> int {
        int a = max(0, w - x), b = max(0, h - y);
        if (w0 + w <= W && h0 + h <= H) {
            return min(a, b);
        } else if (w0 + w <= W) {
            return a;
        } else {
            return b;
        }
    };

    int ans = INT_MAX;
    ans = min(ans, calc(x1, y1));
    ans = min(ans, calc(W - x2, y1));
    ans = min(ans, calc(x1, H - y2));
    ans = min(ans, calc(W - x2, H - y2));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}