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

int calc(int x, ll p) {
    vi a, b;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    while (p) {
        b.push_back(p % 10);
        p /= 10;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int ans = 0;
    for (int i = 0, j = 0; i < ssz(a); i++) {
        if (j == ssz(b) || a[i] != b[j]) {
            ans++;
        } else {
            j++;
        }
        if (i == ssz(a) - 1) {
            ans += ssz(b) - j;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;

    int ans = INT_MAX;
    rep(i, 60) {
        ans = min(ans, calc(n, 1ll << i));
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