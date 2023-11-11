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
    vi a(n); in(a);

    map<int, int> pre, suf;
    for (auto x: a) {
        suf[x]++;
    }

    ll ans = 0;
    for (auto x: a) {
        suf[x]--;
        if (x % k == 0) {
            int p = x / k;
            ll s = x * 1ll * k;
            if (pre.find(p) != pre.end() && s >= -1e9 && s <= 1e9 && suf.find((int)s) != suf.end()) {
                ans += pre[p] * 1ll * suf[(int)s];
            }
        }
        pre[x]++;
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