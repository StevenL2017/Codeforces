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
    int n; cin >> n;
    vi c(n); in(c);
    int k; cin >> k;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[c[i]] = i;
    }

    vi ans(n, 0);
    int mn = *min_element(c.begin(), c.end());
    int mx_cnt = k / mn;
    int last = -1;
    for (auto [x, v]: mp) {
        if (k / x == mx_cnt) {
            last = max(last, v);
        }
    }
    int last2 = last;
    int mod = k % c[last], mx = 0;
    for (int i = last + 1; i < n; i++) {
        if (c[i] > c[last] && mod / (c[i] - c[last]) >= mx) {
            last2 = i;
            mx = mod / (c[i] - c[last]);
        }
    }
    int cnt = mx_cnt - mx;
    ans[0] += cnt;
    if (last < n - 1) {
        ans[last + 1] -= cnt;
    }
    ans[0] += mx;
    if (last2 < n - 1) {
        ans[last2 + 1] -= mx;
    }

    for (int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}