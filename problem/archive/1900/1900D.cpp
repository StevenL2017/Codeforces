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

    int mx = *max_element(a.begin(), a.end());
    vi cnt(mx + 1);
    for (auto x : a) {
        cnt[x]++;
    }

    vi up(mx + 1);
    int pre = 0;
    for (int i = mx; i >= 0; i--) {
        up[i] += pre;
        pre += cnt[i];
    }

    ll ans = 0;
    vector<ll> f(mx + 1);
    for (int i = mx; i > 0; i--) {
        ll pre1 = 0, pre2 = 0;
        for (int j = i; j <= mx; j += i) {
            pre2 += (pre1 * cnt[j] + cnt[j] * 1ll * (cnt[j] - 1) / 2) * up[j]; // a < b < c, a = b < c
            pre2 += cnt[j] * 1ll * (cnt[j] - 1) * (cnt[j] - 2) / 6; // a = b = c;
            pre2 += pre1 * cnt[j] * (cnt[j] - 1) / 2; // a < b = c
            pre1 += cnt[j];
            f[i] -= f[j];
        }
        f[i] += pre2;
        ans += f[i] * i;
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