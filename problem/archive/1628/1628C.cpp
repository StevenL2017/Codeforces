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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(n));
    rep(i, n) in(a[i]);

    int ans = 0;
    rep(_, 2) {
        for (int i = 0; i < n; i += 4) {
            int x = i, y = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                ans ^= a[x][y];
                x -= 2;
                y += 2;
            }
        }
        for (int j = (n % 4 == 0 ? 1 : 3); j < n; j += 4) {
            int x = n - 1, y = j;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                ans ^= a[x][y];
                x -= 2;
                y += 2;
            }
        }
        reverse(a.begin(), a.end());
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