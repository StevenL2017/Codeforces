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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n, 0);
    rep(i, n) {
        string s; cin >> s;
        rep(j, m) {
            if (s[j] == '1') {
                a[i] |= 1ll << (m - 1 - j);
            }
        }
    }

    sorta(a);
    ll ans = ((1ll << m) - 1) / 2;
    ll k = (1ll << m) - n, target = (k - 1) / 2 + 1;
    ll start = max(0ll, (1ll << m) / 2 - 100);
    ll idx = lower_bound(a.begin(), a.end(), start) - a.begin();
    target -= (start - idx);
    for (ll x = start; x < min(1ll << m, start + 200); x++) {
        if (idx < n && x == a[idx]) {
            idx++;
        } else {
            target--;
            if (target == 0) {
                ans = x;
                break;
            }
        }
    }

    string s(m, '0');
    rep(j, m) {
        if (ans >> j & 1) s[m - 1 - j] = '1';
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}