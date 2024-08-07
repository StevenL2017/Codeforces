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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    ll ans = 0;
    vector<ll> f(31, LLONG_MIN);
    f[0] = 0;
    for (auto x: a) {
        vector<ll> g(31, LLONG_MIN);
        for (int i = 30; i >= 0; i--) {
            if (f[i] == LLONG_MIN) {
                continue;
            }
            g[i] = max(g[i], f[i] + (x >> i) - k);
            if (i < 30) {
                g[i + 1] = max(g[i + 1], f[i] + (x >> (i + 1)));
            }
        }
        f = g;
        ans = max(ans, *max_element(f.begin(), f.end()));
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