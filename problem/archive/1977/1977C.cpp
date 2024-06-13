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
    int n; cin >> n;
    vi a(n); in(a);

    int mx = 0;
    map<int, int> mp;
    for (auto x : a) {
        mx = max(mx, x);
        mp[x]++;
    }

    ll l = 1;
    for (auto x : a) {
        l = lcm(l, 1ll * x);
        if (l > mx) {
            cout << n << endl;
            return;
        }
    }

    auto calc = [&] (int target) -> int {
        int cnt = 0, l = 1;
        for (auto [x, c] : mp) {
            if (target % x) continue;
            cnt += c;
            l = lcm(l, x);
        }
        if (l != target) cnt = 0;
        return cnt;
    };

    int ans = 0, x = 2;
    while (x * x <= mx) {
        if (mx % x == 0) {
            if (mp.find(x) == mp.end()) {
                ans = max(ans, calc(x));
            }
            if (x * x < mx && mp.find(mx / x) == mp.end()) {
                ans = max(ans, calc(mx / x));
            }
        }
        x++;
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