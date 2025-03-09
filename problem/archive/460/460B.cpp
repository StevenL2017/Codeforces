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

ll calc(ll s, ll a, ll b, ll c) {
    ll ans = c, p = 1;
    while (a--) {
        p *= s;
    }
    ans += b * p;
    return ans;
}

ll check(ll x) {
    ll ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    vector<ll> ans;
    for (ll s = 1; s <= 81; s++) {
        auto x = calc(s, a, b, c);
        if (check(x) == s && x < 1e9) {
            ans.push_back(x);
        }
    }
    sort(begin(ans), end(ans));

    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}