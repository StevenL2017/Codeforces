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
    int n; cin >> n;
    vi a(n); in(a);

    ll tot = 0;
    rep(i, n) {
        tot += a[i];
    }

    if (tot & 1) {
        cout << "NO\n";
        return;
    }

    ll suf = 0;
    set<ll> s;
    s.insert(0);
    repd(i, n - 1, -1) {
        suf += a[i];
        s.insert(a[i]);
        auto d = suf - (tot - suf);
        if (d >= 0 && d % 2 == 0) {
            if (s.count(d / 2)) {
                cout << "YES\n";
                return;
            }
        }
    }

    ll pre = 0;
    s.clear();
    s.insert(0);
    rep(i, n) {
        pre += a[i];
        s.insert(a[i]);
        auto d = pre - (tot - pre);
        if (d >= 0 && d % 2 == 0) {
            if (s.count(d / 2)) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}