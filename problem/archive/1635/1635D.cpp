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

void solve() {
    int n, p;
    cin >> n >> p;
    vi a(n);
    in(a);

    vi f(p + 1);
    f[0] = 1;
    for (int i = 1; i <= p; i++) {
        f[i] = add(f[i], f[i - 1]);
        if (i > 1) f[i] = add(f[i], f[i - 2]);
    }
    for (int i = 1; i <= p; i++) {
        f[i] = add(f[i], f[i - 1]);
    }

    set<int> s;
    sort(begin(a), end(a));
    for (auto x: a) {
        int y = x;
        bool ok = true;
        while (y) {
            if (s.count(y)) {
                ok = false;
                break;
            }
            if (y & 1) {
                y /= 2;
            } else if (y % 4 == 0) {
                y /= 4;
            } else {
                break;
            }
        }
        if (ok) {
            s.insert(x);
        }
    }

    int ans = 0;
    for (auto x: s) {
        int k = __lg(x) + 1;
        if (k <= p) {
            ans = add(ans, f[p - k]);
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