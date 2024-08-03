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

    int l = 0;
    while (l < n && a[l] == 1) {
        l++;
    }

    if (l == n) {
        cout << 1 << " " << 1 << endl;
        return;
    }

    int r = n - 1;
    while (r >= 0 && a[r] == 1) {
        r--;
    }

    ll tot = 1;
    for (auto x: a) {
        if (tot > 2e14 / x) {
            cout << l + 1 << " " << r + 1 << endl;
            return;
        }
        tot *= x;
    }

    vi idx;
    vector<ll> pre_sum(n + 1, 0), pre_mul(n + 1, 1);
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) idx.push_back(i);
        pre_sum[i + 1] = pre_sum[i] + a[i];
        pre_mul[i + 1] = pre_mul[i] * a[i];
    }

    ll mx = pre_sum[n];
    vi ans(2, 1);
    for (auto i: idx) {
        for (auto j: idx) {
            if (i > j) continue;
            ll cur = pre_sum[i] + pre_mul[j + 1] / pre_mul[i] + pre_sum[n] - pre_sum[j + 1];
            if (cur > mx) {
                mx = cur;
                ans[0] = i + 1;
                ans[1] = j + 1;
            }
        }
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