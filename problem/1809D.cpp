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

const ll X = 1e12;

void solve() {
    string s; cin >> s;

    int n = ssz(s);
    vi pre(n + 1, 0), suf(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i];
        if (s[i] == '1') {
            pre[i + 1]++;
        }
    }
    repd(i, n - 1, -1) {
        suf[i] = suf[i + 1];
        if (s[i] == '0') {
            suf[i]++;
        }
    }

    ll ans = (X + 1) * n;
    rep(i, n + 1) {
        ans = min(ans, (X + 1) * (pre[i] + suf[i]));
        if (i > 0 && i < n && s[i - 1] == '1' && s[i] == '0') {
            ans = min(ans, (X + 1) * (pre[i - 1] + suf[i + 1]) + X);
        }
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