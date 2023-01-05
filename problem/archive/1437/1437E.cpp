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
    int n, k;
    cin >> n >> k;
    vi a(1, INT_MIN), b(1, 0);
    repa(i, 1, n + 1) {
        int x; cin >> x; x -= i;
        a.push_back(x);
    }
    a.push_back(INT_MAX);
    rep(i, k) {
        int x; cin >> x;
        b.push_back(x);
    }
    b.push_back(n + 1);

    int ans = 0;
    rep(i, k + 1) {
        auto l = b[i], r = b[i + 1];
        if (a[l] > a[r]) {
            cout << -1 << endl;
            return;
        }
        vi d;
        repa(j, l + 1, r) {
            if (a[l] <= a[j] && a[j] <= a[r]) {
                auto idx = upper_bound(d.begin(), d.end(), a[j]);
                if (idx == d.end()) d.push_back(a[j]);
                else *idx = a[j];
            }
        }
        ans += (r - l - 1) - ssz(d);
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