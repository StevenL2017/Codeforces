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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    vi c(m);
    in(c);

    sort(a.begin(), a.end());
    int mx = a.back().first;
    vi mn(mx + 1, 2e9);
    for (auto [x, y]: a) {
        mn[x] = min(mn[x], x - y);
    }
    for (int x = 1; x <= mx; x++) {
        mn[x] = min(mn[x], mn[x - 1]);
    }
    vector<ll> cnt(mx + 1);
    for (int x = 1; x <= mx; x++) {
        if (x - mn[x] >= 0) {
            cnt[x] = cnt[x - mn[x]] + 2;
        }
    }

    ll ans = 0;
    for (auto x : c) {
        if (x > mx) {
            ll k = 1ll * (x - mx + mn[mx] - 1) / mn[mx];
            ans += 2 * k + cnt[x - k * mn[mx]];
        } else {
            ans += cnt[x];
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}