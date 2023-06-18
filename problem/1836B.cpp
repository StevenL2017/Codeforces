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
    ll n, k, g;
    cin >> n >> k >> g;

    ll mid = (g + 1) / 2 - 1;
    ll tot = k * 1ll * g;
    if (n * 1ll * mid >= tot) {
        cout << tot << endl;
        return;
    }

    ll ans = (n - 1) * 1ll * mid, res = tot - ans;
    auto r = res % g;
    if (r >= (g + 1) / 2) {
        ans -= g - r;
    } else {
        ans += r;
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