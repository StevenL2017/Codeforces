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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x) {
    return binpow(x, MOD - 2);
}

int divide(int x, int y) {
    return mul(x, inv(y));
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); in(a);

    auto calc = [&] (vi& b) -> int {
        int mn = INT_MAX, mx = INT_MIN;
        map<int, int> cnt;
        for (auto x : b) {
            mn = min(mn, x);
            mx = max(mx, x);
            cnt[x]++;
        }

        if (mx - mn + 1 < m) {
            return 0;
        }

        int ans = 0, cur = 1;
        for (int i = mn; i <= min(mn + m - 1, mx); i++) {
            cur = mul(cur, cnt[i]);
        }
        ans = add(ans, cur);
        for (int i = mn + m; i <= mx; i++) {
            cur = mul(cur, cnt[i]);
            cur = divide(cur, cnt[i - m]);
            ans = add(ans, cur);
        }
        return ans;
    };

    int ans = 0;
    sort(a.begin(), a.end());
    vi b;
    for (int i = 0; i < n; i++) {
        if (!b.empty() && a[i] > b.back() + 1) {
            ans = add(ans, calc(b));
            b.clear();
        }
        b.push_back(a[i]);
    }
    ans = add(ans, calc(b));
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}