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
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);

    int k1 = n / 2, k2 = n - k1;
    vi s1, s2;
    for (int mask = 0; mask < (1 << k1); mask++) {
        int cur = 0;
        for (int i = 0; i < k1; i++) {
            if (mask >> i & 1) {
                cur += a[i];
                cur %= m;
            }
        }
        s1.push_back(cur);
    }
    for (int mask = 0; mask < (1 << k2); mask++) {
        int cur = 0;
        for (int i = 0; i < k2; i++) {
            if (mask >> i & 1) {
                cur += a[k1 + i];
                cur %= m;
            }
        }
        s2.push_back(cur);
    }

    sort(s2.begin(), s2.end());
    int ans = 0;
    for (auto x : s1) {
        int idx = lower_bound(s2.begin(), s2.end(), m - x) - s2.begin();
        if (idx > 0) {
            ans = max(ans, (x + s2[idx - 1]) % m);
        }
        if (idx < ssz(s2)) {
            ans = max(ans, (x + s2[idx]) % m);
        }
        ans = max(ans, (x + s2.back()) % m);
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