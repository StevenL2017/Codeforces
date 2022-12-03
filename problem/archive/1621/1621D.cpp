#include <iostream>
#include <cstdio>
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
#include <random>

using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<vector<ll>> coins(2 * n, vector<ll>(2 * n));
    rep(i, 2 * n) in(coins[i]);

    ll ans = 0;
    repa(i, n, 2 * n) {
        repa(j, n, 2 * n) {
            ans += coins[i][j];
        }
    }

    cout << ans + min({coins[0][n], coins[0][2 * n - 1], coins[n - 1][n], coins[n - 1][2 * n - 1], coins[n][0], coins[2 * n - 1][0], coins[n][n - 1], coins[2 * n - 1][n - 1]}) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}