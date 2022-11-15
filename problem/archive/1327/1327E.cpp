#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 998244353;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7; 

ll mul(ll x, ll y) {
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y) {
    ll z = 1;
    while (y)
    {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

void solve() {
    int n; cin >> n;

    vector<ll> ans(n, 0);
    rep(i, n) {
        int x = i + 1;
        if (n - x - 2 >= 0) {
            ans[i] = 10ll * (2ll * 9 * binpow(10, n - x - 1) % MOD + 1ll * (n - 1 - x) * 9 * 9 * binpow(10, n - x - 2) % MOD);
        }
        else if (n - x - 1 == 0) {
            ans[i] = 10ll * 2 * 9;
        }
        else if (n - x == 0) {
            ans[i] = 10;
        }
        ans[i] %= MOD;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}