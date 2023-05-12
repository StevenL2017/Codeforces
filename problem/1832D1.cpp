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
    int n, q; cin >> n >> q;
    vi a(n); in(a);

    sort(a.begin(), a.end());

    while (q--) {
        int k; cin >> k;

        auto check = [&] (ll x) -> bool {
            int remain = k, j = -1;
            ll tot = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] + remain < x) {
                    return false;
                }
                if (a[i] < x) {
                    tot += a[i] + remain - x;
                    remain--;
                } else {
                    tot += a[i] - x;
                    continue;
                }
                j = i;
            }
            return ((remain % 2 == 0 && tot >= remain / 2) || (remain % 2 == 1 && j < n - 1));
        };

        ll left = -1e18, right = 1e18;
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

        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}