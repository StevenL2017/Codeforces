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
    string s, t;
    cin >> s >> t;

    int n = ssz(s), m = ssz(t);
    vector<vi> f(n + 1, vi(m + 1, 0));
    f[n][0] = 1;
    repd(i, n - 1, 0) {
        rep(j, m + 1) {
            if (j == 0) {
                if (i >= m) f[i][j] = n - i + 1;
                else if (s[i] == t[i]) f[i][j] = f[i + 1][j];
            }
            else if (j == m) {
                f[i][j] = 2 * f[i + 1][j] % MOD;
                if (s[i] == t[j - 1]) f[i][j] = (f[i][j] + f[i + 1][j - 1]) % MOD;
            }
            else {
                if (i + j >= m || s[i] == t[i + j]) f[i][j] = f[i + 1][j];
                if (s[i] == t[j - 1]) f[i][j] = (f[i][j] + f[i + 1][j - 1]) % MOD;
            }
        }
    }

    int ans = f[1][m];
    rep(j, m) {
        if (s[0] == t[j]) {
            ans = (ans + f[1][j]) % MOD;
        }
    }
    cout << (ans * 2) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}