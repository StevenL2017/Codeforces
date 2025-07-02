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
    vi a(n), b(n);
    in(a);
    in(b);

    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += max(0, b[i] - a[i]);
    }

    vi idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&] (int i, int j) { return b[i] > b[j]; });

    ll ans = 0, cost = 0;
    multiset<int> pre;
    if (ssz(pre) == k) {
        ans = max(ans, tot - cost);
    }
    for (int i = 0; i < n; i++) {
        int j = idx[i];
        tot -= max(0, b[j] - a[j]);
        pre.insert(a[j]);
        cost += a[j];
        if (ssz(pre) > k) {
            int mx = *pre.rbegin();
            pre.erase(--pre.end());
            cost -= mx;
        }
        if (ssz(pre) == k) {
            ans = max(ans, tot - cost);
        }
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