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
    ll tot = 0;
    vector<ll> mask(51, 0);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        vi vis(51, 0);
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            tot |= 1ll << x;
            vis[x] = 1;
        }
        for (int x = 1; x <= 50; x++) {
            if (vis[x]) continue;
            for (int y = 1; y <= 50; y++) {
                if (vis[y]) {
                    mask[x] |= 1ll << y;
                }
            }
        }
    }

    int ans = 0;
    for (int x = 1; x <= 50; x++) {
        if (tot >> x & 1) {
            ans = max(ans, __builtin_popcountll(mask[x]));
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