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

void solve() {
    int n, m = 3, k = 2;
    cin >> n;
    vi a(n); in(a);

    if (m > n) {
        cout << 0 << endl;
        return;
    }

    vi cnt(n + 1, 0);
    rep(i, n) {
        cnt[a[i]]++;
    }

    ll ans = 0, tot = 0, j = 1;
    repa(i, 1, n + 1) {
        tot += cnt[i];
        while (i - j > k) {
            tot -= cnt[j];
            j++;
        }
        if (tot >= m) {
            repa(c, 1, min(m, cnt[i]) + 1) {
                ll t1 = 1, t2 = 1;
                rep(d, c) {
                    t1 *= 1ll * (cnt[i] - d);
                }
                rep(d, c) {
                    t1 /= (d + 1);
                }
                rep(d, m - c) {
                    t2 *= 1ll * (tot - cnt[i] - d);
                }
                rep(d, m - c) {
                    t2 /= (d + 1);
                }
                ans += t1 * t2;
            }
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