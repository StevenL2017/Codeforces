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
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    vi a1(k1), a2(k2), a3(k3);
    in(a1); in(a2); in(a3);

    int n = k1 + k2 + k3;
    vi a(n);
    rep(i, k1) {
        a[a1[i] - 1] = 1;
    }
    rep(i, k2) {
        a[a2[i] - 1] = 2;
    }
    rep(i, k3) {
        a[a3[i] - 1] = 3;
    }

    int ans = k1 + k2, mn = 0;
    vi cntl(4, 0), cntr(4, 0);
    rep(i, n) {
        cntr[a[i]]++;
    }
    rep(i, n) {
        cntl[a[i]]++;
        cntr[a[i]]--;
        mn = min(mn, cntl[2] - cntl[1]);
        ans = min(ans, mn + k1 + k3 + cntr[2] - cntr[3]);
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