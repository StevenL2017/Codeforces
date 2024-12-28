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
    ll n, k;
    cin >> n >> k;

    if (k < 1e6 && k * (k + 1) / 2 <= n) {
        ll g = 1, x = 2, y = k * (k + 1) / 2;
        while (x * x <= n) {
            if (n % x == 0) {
                if (y <= x) {
                    g = max(g, n / x);
                }
                if (y <= n / x) {
                    g = max(g, x);
                }
            }
            x++;
        }
        auto m = n - k * (k + 1) / 2 * g;
        vector<ll> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = g * (i + 1);
        }
        ans[k - 1] += m;
        out(ans);
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}