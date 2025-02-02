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

    // 4 * k ^ 2 - 4 * k + 1 + 2 * n * (2 * k + n - 1)
    // 4 * k ^ 2 + (4 * n - 4) * k + 2 * n * n - 2 * n + 1
    ll a = 1, b = 2 * k - 1, c = (k + k + n - 1) * n / 2;
    ll j = (ll)(2 * sqrt(k * k + (n - 1) * k + (2 * n * n - 2 * n + 1) / 4) - b) / 2;
    ll ans = c;
    for (ll i = j - 1; i <= j + 1; i++) {
        ll cur = (k + k + i - 1) * i / 2;
        ans = min(ans, abs(cur - (c - cur)));
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