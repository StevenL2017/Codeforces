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
    int n; cin >> n;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i].second;
    }

    sort(c.begin(), c.end());
    ll ans = 0;
    for (int s = 1; s * s <= 2 * n; s++) {
        vi cnt(n + 1, 0);
        for (auto [a, b] : c) {
            ll x = s * 1ll * a - b;
            if (x >= 1 && x <= n) {
                ans += cnt[x];
            }
            if (a == s) {
                cnt[b]++;
            }
        }
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