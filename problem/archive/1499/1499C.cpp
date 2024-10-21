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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    vector<ll> s(2);
    s[0] = a[0];
    vi c(2), mn(2, 2e9);
    c[0] = 1;
    mn[0] = a[0];
    ll ans = 2e18;
    for (int i = 1; i < n; i++) {
        s[i % 2] += a[i];
        c[i % 2]++;
        mn[i % 2] = min(mn[i % 2], a[i]);
        ans = min(ans, s[0] + mn[0] * 1ll * (n - c[0]) + s[1] + mn[1] * 1ll * (n - c[1]));
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