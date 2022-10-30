#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    ll n; int m;
    cin >> n >> m;
    vi a(m); in(a);

    ll tot = 0;
    vector<int> cnt(64, 0);
    rep(i, m) {
        tot += a[i];
        cnt[__lg(a[i])]++;
    }

    if (tot < n) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    int i = 0;
    while (i < 60) {
        if (n >> i & 1) {
            if (cnt[i] > 0) {
                cnt[i]--;
            } else {
                while (i < 60 && cnt[i] == 0) {
                    i++;
                    ans++;
                }
                cnt[i]--;
                continue;
            }
        }
        cnt[i + 1] += cnt[i] / 2;
        i++;
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