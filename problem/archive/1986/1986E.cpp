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
    vi a(n);
    in(a);

    map<int, vi> mp;
    for (auto x: a) {
        mp[x % k].push_back(x);
    }

    int odd = -1;
    for (auto [x, v]: mp) {
        if (ssz(v) & 1) {
            if (n % 2 == 0 || odd != -1) {
                cout << -1 << endl;
                return;
            }
            odd = x;
        }
    }

    ll ans = 0;
    for (auto [x, v]: mp) {
        sort(v.begin(), v.end());
        if (x != odd) {
            for (int i = 0; i + 1 < ssz(v); i += 2) {
                ans += (v[i + 1] - v[i]) / k;
            }
            continue;
        }
        int m = ssz(v);
        vector<ll> suf(m + 1);
        for (int i = m - 2; i >= 0; i -= 2) {
            suf[i] = suf[i + 2] + (v[i + 1] - v[i]) / k;
        }
        ll cur = 9e18, pre = 0;
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                cur = min(cur, suf[i + 1] + pre);
            } else {
                cur = min(cur, suf[i + 2] + pre + (v[i + 1] - v[i - 1]) / k);
                pre += (v[i] - v[i - 1]) / k;
            }
        }
        ans += cur;
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