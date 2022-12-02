#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    if (t[0] == t[1]) {
        int cnt = 0;
        for (auto& c: s) {
            if (c == t[0]) cnt++;
        }
        int x = min(n, cnt + k);
        cout << x * (x - 1) / 2 << endl;
    } else {
        vector<vector<vi>> f(n + 1, vector<vi>(n + 1, vi(k + 1, -INF)));
        f[0][0][0] = 0;
        rep(i, n) {
            rep(j, i + 1) {
                rep(z, k + 1) {
                    f[i + 1][j][z] = max(f[i + 1][j][z], f[i][j][z]);
                    if (s[i] == t[0]) {
                        f[i + 1][j + 1][z] = max(f[i + 1][j + 1][z], f[i][j][z]);
                        if (z < k) f[i + 1][j][z + 1] = max(f[i + 1][j][z + 1], f[i][j][z] + j);
                    }
                    else if (s[i] == t[1]) {
                        f[i + 1][j][z] = max(f[i + 1][j][z], f[i][j][z] + j);
                        if (z < k) f[i + 1][j + 1][z + 1] = max(f[i + 1][j + 1][z + 1], f[i][j][z]);
                    }
                    else {
                        if (z < k) f[i + 1][j][z + 1] = max(f[i + 1][j][z + 1], f[i][j][z] + j);
                        if (z < k) f[i + 1][j + 1][z + 1] = max(f[i + 1][j + 1][z + 1], f[i][j][z]);
                    }
                }
            }
        }

        int ans = 0;
        rep(j, n + 1) {
            rep(z, k + 1) {
                ans = max(ans, f[n][j][z]);
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}