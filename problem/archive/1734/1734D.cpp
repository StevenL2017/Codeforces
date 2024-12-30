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

    k--;
    vector<pair<ll, ll>> pre, suf;
    ll tot = 0, mn = 0;
    for (int i = k - 1; i >= 0; i--) {
        tot += a[i];
        mn = min(mn, tot);
        if (i > 0 && tot >= 0) {
            pre.emplace_back(tot, -mn);
            tot = mn = 0;
        }
    }
    pre.emplace_back(tot, -mn);
    tot = 0, mn = 0;
    for (int i = k + 1; i < n; i++) {
        tot += a[i];
        mn = min(mn, tot);
        if (i < n - 1 && tot >= 0) {
            suf.emplace_back(tot, -mn);
            tot = mn = 0;
        }
    }
    suf.emplace_back(tot, -mn);

    reverse(pre.begin(), pre.end());
    reverse(suf.begin(), suf.end());

    ll cur = a[k];
    bool ok = true;
    while (ok) {
        ok = false;
        if (!pre.empty() && pre.back().second <= cur) {
            cur += pre.back().first;
            pre.pop_back();
            ok = true;
        }
        if (!suf.empty() && suf.back().second <= cur) {
            cur += suf.back().first;
            suf.pop_back();
            ok = true;
        }
        if (pre.empty() || suf.empty()) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}