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

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; });

    ll ans = 0;
    int m1 = idx[(n - 2) / 2], m2 = idx[n / 2];;
    for (int i = 0; i < n; i++) {
        int j = idx[i];
        if (!b[j]) continue;
        ll cur = 1ll * a[j] + k + a[(i < n / 2 ? m2 : m1)];
        ans = max(ans, cur);
    }

    auto check = [&] (int x) -> bool {
        int cnt = 0, s = k;
        for (int i = n - 2; i >= 0; i--) {
            int j = idx[i];
            if (a[j] >= x) {
                cnt++;
            } else {
                if (s >= x - a[j] && b[j]) {
                    s -= x - a[j];
                    cnt++;
                }
            }
        }
        return cnt >= (n + 1) / 2;
    };

    int left = a[idx[0]], right = 2e9;
    int mxc = left;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            mxc = mid;
        } else {
            right = mid - 1;
        }
    }
    ans = max(ans, 1ll * a[idx[n - 1]] + mxc);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}