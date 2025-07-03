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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    in(a);
    in(b);

    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        c.emplace_back(a[i], 0);
        c.emplace_back(b[i], 1);
    }
    sort(begin(c), end(c));

    ll ans = 0;
    int cnt = n, bad = 0;
    for (int i = 0; i < 2 * n; ) {
        auto [x, op] = c[i];
        if (bad <= k) {
            ans = max(ans, x * 1ll * cnt);
        }
        while (i < 2 * n && c[i].first == x) {
            bad += (int)(c[i].second == 0);
            bad -= (int)(c[i].second == 1);
            cnt -= (int)(c[i].second == 1);
            i++;
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