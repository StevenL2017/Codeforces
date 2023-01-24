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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    sorta(a);
    vector<ll> pre_sum(1, 0);
    rep(i, n) {
        pre_sum.push_back(pre_sum.back() + a[i]);
    }

    ll ans = LLONG_MAX;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && a[j] == a[i]) j++;
        int cur_cnt = j - i;
        if (cur_cnt >= k) {
            cout << 0 << endl;
            return;
        }
        int pre_cnt = i, suf_cnt = n - j;
        ll pre_ops = (a[i] - 1) * 1ll * pre_cnt - pre_sum[i];
        ll suf_ops = pre_sum[n] - pre_sum[j] - (a[i] + 1) * 1ll * suf_cnt;
        if (cur_cnt + pre_cnt >= k) {
            ans = min(ans, pre_ops + k - cur_cnt);
        }
        if (cur_cnt + suf_cnt >= k) {
            ans = min(ans, suf_ops + k - cur_cnt);
        }
        ans = min(ans, pre_ops + suf_ops + k - cur_cnt);
        i = j;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}