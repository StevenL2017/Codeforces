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
    int n;
    cin >> n;
    vi a(n), b(n);
    in(a);
    in(b);

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = lcm(1ll * a[i], 1ll * b[i]);
    }

    ll pre = 0, suf = 0;
    for (int i = 0; i < n; i++) {
        pre = gcd(pre, ans[i]);
        if (pre != a[i]) {
            cout << "NO" << endl;
            return;
        }
        suf = gcd(suf, ans[n - 1 - i]);
        if (suf != b[n - 1 - i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}