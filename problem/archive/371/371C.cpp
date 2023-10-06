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
    string s; cin >> s;
    vi a(3); in(a);
    vi p(3); in(p);
    ll r; cin >> r;

    vi cnt(3, 0);
    for (auto c : s) {
        if (c == 'B') {
            cnt[0]++;
        } else if (c == 'S') {
            cnt[1]++;
        } else {
            cnt[2]++;
        }
    }

    auto check = [&] (ll x) -> bool {
        ll res = 0;
        for (int i = 0; i < 3; i++) {
            ll cur = max(0ll, x * cnt[i] - a[i]) * p[i];
            if (cur > r) return false;
            res += cur;
            if (res > r) return false;
        }
        return true;
    };

    ll left = 0, right = 1e14;
    ll ans = left;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
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