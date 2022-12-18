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

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(n, 0));
    rep(i, n) {
        repa(j, i, n) {
            cin >> a[i][j];
        }
    }

    auto check = [&] (int cnt, int last) -> bool {
        rep(i, cnt) {
            if (a[i][cnt - 1] == 1 && last > i) return false;
            if (a[i][cnt - 1] == 2 && last <= i) return false;
        }
        return true;
    };

    vector<vi> f(n + 1, vi(n + 1, 0));
    if (a[0][0] != 2) f[1][0] = 2;
    repa(i, 1, n) {
        rep(j, i) {
            for (int k: vi({j, i})) {
                if (check(i + 1, k)) {
                    f[i + 1][k] += f[i][j];
                    f[i + 1][k] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    rep(i, n) {
        ans += f[n][i];
        ans %= MOD;
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