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
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;

    vi c(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            c[i] = 1;
            cnt++;
        }
    }

    if (cnt & 1) {
        cout << -1 << endl;
        return;
    }

    if (x >= y) {
        if (cnt == 2) {
            int l = 0, r = n - 1;
            while (l < n && c[l] == 0) l++;
            while (r >= 0 && c[r] == 0) r--;
            cout << (l + 1 == r ? min(x, 2 * y) : y) << endl;
        } else {
            cout << cnt / 2 * 1ll * y << endl;
        }
        return;
    }

    vector<vector<ll>> f0(n + 1, vector<ll>(n + 1, 1e18)), f1(n + 1, vector<ll>(n + 1, 1e18));
    if (c[0] == 0) f0[1][0] = 0;
    else f1[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 0; j--) {
            if (c[i - 1] == 0) {
                f0[i][j] = min(f0[i - 1][j], f1[i - 1][j]);
                f1[i][j] = min(f0[i - 1][j] + y, f1[i - 1][j] + x);
                if (j > 1) f1[i][j] = min({f1[i][j], f0[i - 1][j - 2] + x, f1[i - 1][j - 2] + y});
            } else {
                if (j < i) f0[i][j] = min(f0[i - 1][j + 1] + y, f1[i - 1][j + 1] + x);
                if (j > 0) f0[i][j] = min({f0[i][j], f0[i - 1][j - 1] + x, f1[i - 1][j - 1] + y});
                if (j > 0) f1[i][j] = min(f0[i - 1][j - 1], f1[i - 1][j - 1]);
            }
        }
    }

    cout << f0[n][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}