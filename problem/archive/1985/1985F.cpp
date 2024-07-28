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
    int h, n;
    cin >> h >> n;
    vi a(n), c(n);
    in(a);
    in(c);

    auto check = [&] (ll x) -> bool {
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            tot += a[i] * ((x + c[i] - 1) / c[i]);
            if (tot >= h) return true;
        }
        return false;
    };

    ll left = 1, right = 4e10;
    ll ans = right;
    while (left <= right) {
        auto mid = (left + right) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
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