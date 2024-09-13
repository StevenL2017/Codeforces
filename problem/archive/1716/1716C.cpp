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
    vector<vi> a(2, vi(n));
    for (int i = 0; i < 2; i++) {
        in(a[i]);
    }

    vector<vector<ll>> pre(2, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            int row = (i & 1) ^ j;
            pre[row][i] = max(((row & 1) == (i & 1) ? pre[row][i - 1] : pre[row ^ 1][i]) + 1, 1ll * a[row][i] + 1);
        }
    }

    vector<vector<ll>> suf(2, vector<ll>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int row = 0; row < 2; row++) {
            suf[row][i] = max(1ll * a[row][i] + (i != 0 || row != 0) + (n - i - 1) * 2 + 1, 1ll * a[row ^ 1][i] + 1);
            if (i < n - 1) {
                suf[row][i] = max(suf[row][i], suf[row][i + 1] + 1);
            }
        }
    }

    ll ans = 1e18;
    for (int i = n - 1; i >= 0; i--) {
        int row = i & 1;
        auto cur = max(pre[row][i] + (n - i - 1) * 2 + 1, suf[row][i]);
        ans = min(ans, cur);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}