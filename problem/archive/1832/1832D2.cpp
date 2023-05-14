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
    vi pre(n + 1, 1e9);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = min(pre[i], a[i] - i);
    }
    ll s = accumulate(a.begin(), a.end(), 0ll);
    s -= n * 1ll * (n - 1) / 2;

    vector<ll> ans;
    while (q--) {
        int k; cin >> k;

        if (k < n) {
            ans.push_back(min(pre[k] + k, a[k]));
        } else {
            if (k % 2 == n % 2) {
                auto mn = pre[n];
                auto ns = s - mn * 1ll * n;
                ans.push_back(mn + k - (max(0ll, (k - n) / 2 - ns) + n - 1) / n);
            } else {
                auto mn = min(pre[n - 1], a[n - 1] - k);
                auto ns = (s + n - 1 - k) - mn * 1ll * n;
                ans.push_back(mn + k - (max(0ll, (k - (n - 1)) / 2 - ns) + n - 1) / n);
            }
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}