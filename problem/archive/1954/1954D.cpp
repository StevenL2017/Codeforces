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

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);

    sort(a.begin(), a.end());

    int s = 0;
    for (auto x: a) {
        s += x;
    }

    vi cnt(s + 1);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int x = s - a[i]; x >= 0; x--) {
            cnt[x + a[i]] = add(cnt[x + a[i]], cnt[x]);
        }
    }

    int ans = 0;
    for (int x = 0; x <= s; x++) {
        ans = add(ans, mul(cnt[x], (x + 1) / 2));
    }
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < a[i]; x++) {
            ans = add(ans, mul(cnt[x], a[i] - (a[i] + x + 1) / 2));
        }
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