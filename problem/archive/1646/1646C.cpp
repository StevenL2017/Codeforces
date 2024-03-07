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

void solve() {
    ll n; cin >> n;

    vector<ll> f;
    ll x = 1, c = 1;
    while (x <= n) {
        f.push_back(x);
        c++;
        x *= c;
    }

    int ans = __builtin_popcountll(n);
    int m = ssz(f);
    for (int mask = 0; mask < (1 << m); mask++) {
        ll cur = 0;
        set<ll> s;
        for (int i = 0; i < m; i++) {
            if (mask >> i & 1) {
                cur += f[i];
                s.insert(f[i]);
            }
        }
        if (cur > n) continue;
        ll rem = n - cur;
        bool ok = true;
        for (int i = 0; i < 60; i++) {
            if (rem >> i & 1) {
                if (s.count(1 << i)) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;
        ans = min(ans, __builtin_popcountll(rem) + __builtin_popcountll(mask));
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