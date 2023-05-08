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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y) {
    return add(x, -y);
}

int m, d;
string a, b;

int f[2002][2001][2];

int calc(const string& s) {
    int n = ssz(s);
    rep(i, n + 1) {
        rep(j, m) {
            rep(k, 2) {
                f[i][j][k] = 0;
            }
        }
    }
    f[0][0][1] = 1;
    repa(i, 1, n + 1) {
        rep(j, m) {
            rep(k, 2) {
                if (i & 1) {
                    repa(x, (int)(i == 1 && n > 1), (k == 0 ? 10 : s[i - 1] - '0' + 1)) {
                        if (x == d) continue;
                        int nj = (10 * j + x) % m;
                        int nk = k == 1 && x == s[i - 1] - '0';
                        f[i][nj][nk] = add(f[i][nj][nk], f[i - 1][j][k]);
                    }
                } else {
                    if (k == 0 || k == 1 && d <= s[i - 1] - '0') {
                        int nj = (10 * j + d) % m;
                        int nk = k == 1 && d == s[i - 1] - '0';
                        f[i][nj][nk] = add(f[i][nj][nk], f[i - 1][j][k]);
                    }
                }
            }
        }
    }
    return add(f[n][0][0], f[n][0][1]);
}

int is_magic(const string& s) {
    int n = ssz(s), j = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            if (s[i] != d + '0') {
                return 0;
            }
        } else {
            if (s[i] == d + '0') {
                return 0;
            }
        }
        j = (10 * j + s[i] - '0') % m;
    }
    return j % m == 0;
}

void solve() {
    cin >> m >> d >> a >> b;

    cout << add(sub(calc(b), calc(a)), is_magic(a)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}