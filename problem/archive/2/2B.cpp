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

int mat[1005][1005][2];
int f[1005][1005][2];
int path[1005][1005][2];

void solve() {
    int n; cin >> n;
    bool has_zero = false;
    int zero_r, zero_c;
    rep(i, n) {
        rep(j, n) {
            int x; cin >> x;
            if (x == 0) {
                has_zero = true;
                zero_r = i;
                zero_c = j;
                mat[i][j][0] = 1;
                mat[i][j][1] = 1;
                continue;
            }
            while (x % 2 == 0) {
                mat[i][j][0]++;
                x /= 2;
            }
            while (x % 5 == 0) {
                mat[i][j][1]++;
                x /= 5;
            }
        }
    }

    rep(i, n) {
        rep(j, n) {
            rep(k, 2) {
                if (i == 0 && j == 0) {
                    f[i][j][k] = mat[i][j][k];
                }
                else if (i == 0) {
                    f[i][j][k] = f[i][j - 1][k] + mat[i][j][k];
                    path[i][j][k] = 1;
                }
                else if (j == 0) {
                    f[i][j][k] = f[i - 1][j][k] + mat[i][j][k];
                }
                else {
                    if (f[i][j - 1][k] < f[i - 1][j][k]) {
                        f[i][j][k] = f[i][j - 1][k] + mat[i][j][k];
                        path[i][j][k] = 1;
                    } else {
                        f[i][j][k] = f[i - 1][j][k] + mat[i][j][k];
                    }
                }
            }
        }
    }

    int k = f[n - 1][n - 1][0] < f[n - 1][n - 1][1] ? 0 : 1;
    string s;
    if (has_zero && f[n - 1][n - 1][k] > 1) {
        rep(i, zero_r) {
            s += 'D';
        }
        rep(i, zero_c) {
            s += 'R';
        }
        rep(i, n - zero_r - 1) {
            s += 'D';
        }
        rep(i, n - zero_c - 1) {
            s += 'R';
        }
        cout << 1 << endl << s << endl;
    } else {
        int i = n - 1, j = n - 1;
        while (i > 0 || j > 0) {
            if (path[i][j][k]) {
                s += 'R';
                j--;
            } else {
                s += 'D';
                i--;
            }
        }
        reverse(s.begin(), s.end());
        cout << f[n - 1][n - 1][k] << endl << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}