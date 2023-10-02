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
    int n, q;
    cin >> n >> q;
    vi a(n); in(a);
    vi d(n + 1, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        d[l]++;
        d[r + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
    }
    d.pop_back();

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return d[i] < d[j]; });
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * 1ll * d[idx[i]];
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