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

const int MOD = 998244353;

void solve() {
    int n; cin >> n;

    ll ans = 0;
    vector<ll> pts(1, 0), pre(1, 0);
    rep(i, n) {
        int x, y, s;
        cin >> x >> y >> s;
        
        pts.push_back(x);
        auto idx = lower_bound(pts.begin(), pts.end(), y) - pts.begin();
        auto cur = pre.back() - pre[idx - 1] + 1ll * (x - y);
        cur %= MOD;
        pre.push_back(pre.back() + cur);

        if (s == 1) {
            ans += cur;
            ans %= MOD;
        }
    }

    cout << (ans + pts.back() + 1) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}