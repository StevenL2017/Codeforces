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

    auto check = [&] (int x) -> bool {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < x) continue;
            cnt += (a[i] - x) / b[i] + 1;
            if (cnt > k) return false;
        }
        return true;
    };

    int left = 0, right = *max_element(begin(a), end(a)) + 1;
    int x = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            x = mid;
        } else {
            left = mid + 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) continue;
        int c = (a[i] - x) / b[i] + 1;
        ans += c * 1ll * a[i] - c * 1ll * (c - 1) / 2 * b[i];
        k -= c;
    }
    ans += k * 1ll * max(0, x - 1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}