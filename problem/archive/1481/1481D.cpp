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
    vector<string> e(n); in(e);

    rep(i, n) {
        int u = 0, v = 0;
        rep(j, n) {
            if (i == j) continue;
            if ((m & 1) || e[i][j] == e[j][i]) {
                cout << "YES\n";
                rep(k, (m + 1) / 2) {
                    cout << i + 1 << " " << j + 1 << " ";
                }
                if (m % 2 == 0) cout << i + 1;
                cout << endl;
                return;
            }
            if (e[i][j] == 'a' && e[j][i] == 'b') {
                u = j + 1;
            }
            else if (e[i][j] == 'b' && e[j][i] == 'a') {
                v = j + 1;
            }
            if (u > 0 && v > 0) {
                cout << "YES\n";
                if (m % 4 == 2) {
                    vi a = {u, i + 1, v, i + 1};
                    rep(k, m + 1) {
                        cout << a[k % 4] << " ";
                    }
                } else {
                    vi a = {i + 1, v, i + 1, u};
                    rep(k, m + 1) {
                        cout << a[k % 4] << " ";
                    }
                }
                cout << endl;
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}