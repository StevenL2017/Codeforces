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
    int n; cin >> n;
    vector<ll> a(n); in(a);

    vi cnt(60, 0);
    rep(i, n) {
        rep(j, 60) {
            if (a[i] >> j & 1) {
                cnt[j]++;
            }
        }
    }

    int ans = 0;
    rep(i, n) {
        int tot_and = 0, tot_or = 0;
        rep(j, 60) {
            if (a[i] >> j & 1) {
                tot_and = add(tot_and, mul((1ll << j) % MOD, cnt[j]));
                tot_or = add(tot_or, mul((1ll << j) % MOD, n));
            } else {
                tot_or = add(tot_or, mul((1ll << j) % MOD, cnt[j]));
            }
        }
        ans = add(ans, mul(tot_and, tot_or));
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