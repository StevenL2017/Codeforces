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

set<ll> s;

void precalc() {
    for (ll k = 2; k <= (ll)(1e6); k++) {
        ll x = 1 + k, p = k * k;
       for (int i = 0; i < 63; i++) {
            x += p;
            if (x > (ll)(1e18)) break;
            s.insert(x);
            if (p > (ll)(1e18) / k) break;
            p *= k;
        }
    }
}

void solve() {
    ll n;
    cin >> n;

    if (s.count(n)) {
        cout << "YES\n";
        return;
    }

    if (n < 7) {
        cout << "NO\n";
        return;
    }

    ll k = (ll)(sqrtl(n - 1));
    if (1ll + k + k * k == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}