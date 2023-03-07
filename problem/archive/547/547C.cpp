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

const int N = 5e5 + 3;

vi p[N];
int cnt[N], mul[N];

void get_primes() {
    for (int i = 2; i < N; i++) {
        if (p[i].empty()) {
            for (int j = i; j < N; j += i) {
                p[j].push_back(i);
            }
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); in(a);

    vi vis(n, 0);
    rep(i, n) {
        vis[i] = 1;
    }

    get_primes();

    ll ans = 0;
    while (q--) {
        int x; cin >> x;
        x--;

        rep(mask, 1 << ssz(p[a[x]])) {
            if (!mask) {
                mul[mask] = 1;
            } else {
                mul[mask] = mul[mask & (mask - 1)] * p[a[x]][__builtin_ctz(mask)];
            }
            if (vis[x] < 0) {
                cnt[mul[mask]]--;
            }
            if (__builtin_popcount(mask) & 1) {
                ans -= cnt[mul[mask]] * vis[x];
            } else {
                ans += cnt[mul[mask]] * vis[x];
            }
            if (vis[x] > 0) {
                cnt[mul[mask]]++;
            }
        }
        vis[x] *= -1;

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}