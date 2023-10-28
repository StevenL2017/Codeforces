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
    int n; cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    } else if (n == 2) {
        cout << 2 << endl;
        return;
    } else if (n & 1) {
        cout << n * 1ll * (n - 1) * (n - 2) << endl;
        return;
    }

    ll ans = 0;
    for (ll i = max(1, n - 50); i <= n; i++) {
        for (ll j = max(1, n - 50); j <= n; j++) {
            for (ll k = max(1, n - 50); k <= n; k++) {
                ans = max(ans, lcm(lcm(i, j), k));
            }
        }
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