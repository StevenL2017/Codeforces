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

    vector<ll> pre(n + 1), ppre(n + 2);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    for (int i = 0; i <= n; i++) {
        ppre[i + 1] = ppre[i] + pre[i];
    }

    vector<ll> start(1);
    for (int i = n; i >= 1; i--) {
        start.push_back(start.back() + i);
    }

    auto get_partial = [&] (int l, int r1, int r2) -> ll {
        // block l with [r1, r2]
        if (r2 < r1) {
            return 0ll;
        }
        ll ans = ppre[r2 + 2] - ppre[r1 + 1];
        ll cnt = r2 - r1 + 1;
        ans -= cnt * pre[l];
        return ans;
    };

    vector<ll> pre_block(n + 1);
    for (int i = 0; i < n; i++) {
        auto cur = get_partial(i, i, n - 1);
        pre_block[i + 1] = pre_block[i] + cur;
    }

    auto convert = [&] (ll i) -> pair<int, int> {
        auto idx = upper_bound(begin(start), end(start), i) - begin(start) - 1;
        return {idx, idx + i - start[idx]};
    };

    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;

        auto left = convert(l);
        auto right = convert(r);
        ll ans = pre_block[right.first + 1] - pre_block[left.first];
        ans -= get_partial(left.first, left.first, left.second - 1);
        ans -= get_partial(right.first, right.second + 1, n - 1);
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}