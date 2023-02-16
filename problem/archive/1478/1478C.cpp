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
    vector<ll> d(2 * n); in(d);

    sortd(d);
    ll a = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (d[i] != d[i + 1] || (d[i] & 1) || (d[i] == 0)) {
            cout << "NO\n";
            return;
        }
        if (i == 0) {
            if (d[i] % (2 * n) != 0) {
                cout << "NO\n";
                return;
            }
            a = d[i] / (2 * n);
            continue;
        }
        auto x = d[i - 2] - d[i];
        if (x == 0 || x % (2 * n - i) != 0) {
            cout << "NO\n";
            return;
        }
        a -= x / (2 * n - i);
    }

    if (a > 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}