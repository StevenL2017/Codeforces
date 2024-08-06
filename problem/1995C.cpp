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

    ll ans = 0;
    vector<ll> cnt(n);
    for (int i = 1; i < n; i++) {
        ll x = a[i - 1], y = a[i];
        if (x == 1) continue;
        if (y == 1) {
            cout << -1 << endl;
            return;
        }
        if (x <= y) {
            ll cur = 0;
            while (x * x <= y) {
                x *= x;
                cur++;
            }
            cnt[i] = max(0ll, cnt[i - 1] - cur);
        } else {
            ll cur = 0;
            while (y < x) {
                y *= y;
                cur++;
            }
            cnt[i] = cnt[i - 1] + cur;
        }
        ans += cnt[i];
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