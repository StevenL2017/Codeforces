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
    int n; cin >> n;
    vector<ll> a(n), b(n); in(a); in(b);

    vector<ll> pre(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i] + b[i];
    }

    vector<ll> cnt(n, 0), diff(n, 0);
    rep(i, n) {
        auto idx = upper_bound(pre.begin(), pre.end(), a[i] + pre[i]) - pre.begin();
        ll d = a[i] + pre[i] - pre[idx - 1];
        cnt[i]++;
        if (idx - 1 < n) {
            cnt[idx - 1]--;
            diff[idx - 1] += d;
        }
    }

    rep(i, n - 1) {
        cnt[i + 1] += cnt[i];
    }

    vector<ll> ans(n, 0);
    rep(i, n) {
        ans[i] = cnt[i] * 1ll * b[i] + diff[i];
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