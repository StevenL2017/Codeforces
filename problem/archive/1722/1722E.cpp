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
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    int mx_h = 0, mx_w = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        mx_h = max(mx_h, a[i].first);
        mx_w = max(mx_w, a[i].second);
    }

    vector<vector<ll>> pre(mx_h + 1, vector<ll>(mx_w + 1, 0));
    for (auto [h, w]: a) {
        pre[h][w] += h * 1ll * w;
    }
    for (int i = 1; i <= mx_h; i++) {
        for (int j = 1; j <= mx_w; j++) {
            pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        }
    }

    while (q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;

        int t = hs + 1, d = min(mx_h, hb - 1);
        int l = ws + 1, r = min(mx_w, wb - 1);
        ll ans = 0;
        if (t <= d && l <= r) {
            ans = pre[d][r] - pre[t - 1][r] - pre[d][l - 1] + pre[t - 1][l - 1];
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}