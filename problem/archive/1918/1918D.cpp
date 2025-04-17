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
    vi a(n);
    in(a);

    auto check = [&] (ll m) -> bool {
        ll tot = 0, pre = 0;
        multiset<ll> s;
        s.insert(0);
        vector<ll> f(n + 1);
        for (int i = 0, j = 0; i < n; i++) {
            tot += a[i];
            while (pre > m) {
                pre -= a[j];
                s.extract(f[j]);
                j++;
            }
            f[i + 1] = *s.begin() + a[i];
            s.insert(f[i + 1]);
            pre += a[i];
        }
        for (int i = 0; i <= n; i++) {
            if (f[i] <= m && tot <= m) {
                return true;
            }
            if (i < n) {
                tot -= a[i];
            }
        }
        return false;
    };

    ll left = 0, right = 1e15;
    ll ans = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
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