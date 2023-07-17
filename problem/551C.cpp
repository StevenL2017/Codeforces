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
    int n, m; cin >> n >> m;
    vi a(n); in(a);

    auto check = [&] (ll x) -> bool {
        vi b = a;
        int i = n - 1;
        for (int j = 0; j < m; j++) {
            while (i >= 0 && b[i] == 0) i--;
            ll t = x - (i + 1);
            if (t <= 0) break;
            while (i >= 0 && b[i] <= t) t -= b[i--];
            if (i >= 0) b[i] -= t;
        }
        return i < 0;
    };

    ll left = 0, right = 1e18;
    ll ans = right;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
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
    // cin >> t;
    while (t--) solve();
}