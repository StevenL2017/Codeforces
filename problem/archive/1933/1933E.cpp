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

    vi pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    auto calc = [&] (int u, int l, int r) -> ll {
        int s = 1ll * (pre[r] - pre[l - 1]);
        return (u + u + 1 - s) * 1ll * s / 2;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        int idx = lower_bound(begin(pre), end(pre), pre[l - 1] + u) - begin(pre);
        ll mx = -1, ans = idx;
        for (int i = max(l, idx - 2); i <= min(n, idx + 2); i++) {
            auto cur = calc(u, l, i);
            if (cur > mx) {
                mx = cur;
                ans = i;
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
    cin >> t;
    while (t--) solve();
}