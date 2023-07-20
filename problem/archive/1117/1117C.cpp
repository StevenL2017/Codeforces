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
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    int n; cin >> n;
    string s; cin >> s;

    int dx = x2 - x1, dy = y2 - y1;
    int ddx = 0, ddy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') ddx--;
        else if (s[i] == 'R') ddx++;
        else if (s[i] == 'D') ddy--;
        else ddy++;
    }

    ll ans = LLONG_MAX;
    ll cx = 0, cy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') cx--;
        else if (s[i] == 'R') cx++;
        else if (s[i] == 'D') cy--;
        else cy++;
        ll up = 0, down = 0, k = 0, x = 0, y = 0;
        // x >= 0, y >= 0
        up = dx + dy - (cx + cy) - (i + 1);
        down = n + ddx + ddy;
        if (down > 0) {
            k = (up + down - 1) / down;
            x = dx - k * ddx - cx;
            y = dy - k * ddy - cy;
            if (x >= 0 && y >= 0 && x + y <= k * n + i + 1) {
                ans = min(ans, k * n + i + 1);
            }
        }
        // x <= 0, y >= 0
        up = -dx + dy - (-cx + cy) - (i + 1);
        down = n - ddx + ddy;
        if (down > 0) {
            k = (up + down - 1) / down;
            x = dx - k * ddx - cx;
            y = dy - k * ddy - cy;
            if (x <= 0 && y >= 0 && -x + y <= k * n + i + 1) {
                ans = min(ans, k * n + i + 1);
            }
        }
        // x >= 0, y <= 0
        up = dx - dy - (cx - cy) - (i + 1);
        down = n + ddx - ddy;
        if (down > 0) {
            k = (up + down - 1) / down;
            x = dx - k * ddx - cx;
            y = dy - k * ddy - cy;
            if (x >= 0 && y <= 0 && x - y <= k * n + i + 1) {
                ans = min(ans, k * n + i + 1);
            }
        }
        // x <= 0, y <= 0
        up = -dx - dy + (cx + cy) - (i + 1);
        down = n - ddx - ddy;
        if (down > 0) {
            k = (up + down - 1) / down;
            x = dx - k * ddx - cx;
            y = dy - k * ddy - cy;
            if (x <= 0 && y <= 0 && -x - y <= k * n + i + 1) {
                ans = min(ans, k * n + i + 1);
            }
        }
    }

    cout << (ans < LLONG_MAX ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}