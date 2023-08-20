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
    ll l, r; cin >> l >> r;

    function<ll(ll ,ll)> dfs = [&] (ll l, ll r) -> ll {
        if (l == r) return l;
        for (int i = 61; i >= 0; i--) {
            ll cur = 1ll << i;
            if (cur <= r) {
                if (cur <= l) {
                    return dfs(l - cur, r - cur) + cur;
                } else if (cur * 2 - 1 <= r) {
                    return cur * 2 - 1;
                } else {
                    return cur - 1;
                }
            }
        }
        return 0;
    };

    cout << dfs(l, r) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}