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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    auto calc = [&] (ll t) -> ll {
        map<ll, int> cnt;
        cnt[0] = 1;
        ll ans = 0, pre = 0;
        for (auto x: a) {
            pre += x;
            ans += cnt[pre - t];
            cnt[pre]++;
        }
        return ans;
    };

    if (k == 1) {
        cout << calc(1) << endl;
        return;
    }
    if (k == -1) {
        cout << calc(1) + calc(-1) << endl;
        return;
    }

    ll ans = 0;
    for (ll p = 1; abs(p) <= 1e14; p *= k) {
        ans += calc(p);
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