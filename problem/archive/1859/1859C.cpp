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

    ll ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans += i * 1ll * i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ll tot = 0;
            int mx = i * j, pre = 1;
            set<int> s;
            for (int k = n; k >= 1; k--) {
                int cur = mx / k;
                cur = min(cur, n);
                if (cur == 0) {
                    tot = -1;
                    break;
                }
                for (int x = pre; x <= cur; x++) {
                    s.insert(x);
                }
                pre = cur + 1;
                if (s.empty()) {
                    tot = -1;
                    break;
                }
                tot += k * 1ll * (*s.rbegin());
                s.erase(*s.rbegin());
            }
            if (tot == -1) continue;
            ans = max(ans, tot - 1ll * mx);
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