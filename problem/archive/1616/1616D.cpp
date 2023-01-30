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
    vi a(n); in(a);
    int x; cin >> x;

    vector<vi> f(n, vi(3, 0));
    f[0][1] = 1;
    repa(i, 1, n) {
        f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
        f[i][1] = f[i - 1][0] + 1;
        if (a[i] + a[i - 1] >= 2 * x) {
            f[i][2] = max(f[i][2], f[i - 1][1] + 1);
        }
        if (i - 2 >= 0 && a[i] + a[i - 1] >= 2 * x && a[i] + a[i - 1] + a[i - 2] >= 3 * x) {
            f[i][2] = max(f[i][2], f[i - 1][2] + 1);
        }
    }

    cout << *max_element(f[n - 1].begin(), f[n - 1].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}