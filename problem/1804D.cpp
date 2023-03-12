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
    int n, m; cin >> n >> m;
    vector<string> a(n); in(a);

    int mn = 0, mx = 0, c2 = m / 4;
    for (auto& s: a) {
        auto x = s;
        int cur_mn = 0, cur_c2 = c2;
        for (int i = 0; i < m; ) {
            if (i + 1 < m && x[i] == '1' && x[i + 1] == '1' && cur_c2 > 0) {
                x[i] = x[i + 1] = '0';
                cur_c2--;
                i += 2;
            } else {
                i++;
            }
        }
        cur_mn += c2 - cur_c2;
        rep(i, m) {
            if (x[i] == '1') {
                cur_mn++;
            }
        }
        mn += cur_mn;

        auto y = s;
        int cur_mx = 0;
        cur_c2 = c2;
        for (int i = 0; i < m; ) {
            if (i + 1 < m && !(y[i] == '1' && y[i + 1] == '1') && cur_c2 > 0) {
                if (y[i] == '1' || y[i + 1] == '1') {
                    cur_mx++;
                }
                y[i] = y[i + 1] = '0';
                cur_c2--;
                i += 2;
            } else {
                i++;
            }
        }
        for (int i = 0; i < m; ) {
            if (i + 1 < m && y[i] == '1' && y[i + 1] == '1' && cur_c2 > 0) {
                cur_mx++;
                y[i] = y[i + 1] = '0';
                cur_c2--;
                i += 2;
            } else {
                i++;
            }
        }
        rep(i, m) {
            if (y[i] == '1') {
                cur_mx++;
            }
        }
        mx += cur_mx;
    }

    cout << mn << " " << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}