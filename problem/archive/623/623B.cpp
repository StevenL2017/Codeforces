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

const int N = 1e6 + 3;

int n, c1, c2;
int a[N];
set<int> s;

void get_primes(int x) {
    int d = 2;
    while (d * d <= x) {
        if (x % d == 0) {
            s.insert(d);
            while (x % d == 0) {
                x /= d;
            }
        }
        d++;
    }
    if (x > 1) {
        s.insert(x);
    }
}

void solve() {
    cin >> n >> c1 >> c2;
    rep(i, n) cin >> a[i];

    repa(i, -1, 2) {
        get_primes(a[0] + i);
        get_primes(a[n - 1] + i);
    }

    ll ans = LLONG_MAX;
    for (auto& p: s) {
        vector<vector<ll>> f(n + 1, vector<ll>(3, 2e18));
        f[0][0] = 0;
        rep(i, n) {
            int m = a[i] % p;
            ll cost = 2e18;
            if (m == 0) cost = 0;
            else if (m == 1 || m == p - 1) cost = c2;
            if (cost < 2e18) f[i + 1][0] = f[i][0] + cost;
            f[i + 1][1] = min(f[i][0], f[i][1]) + c1;
            if (cost < 2e18) f[i + 1][2] = min(f[i][1], f[i][2]) + cost;
        }
        ans = min(ans, *min_element(f[n].begin(), f[n].end()));
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