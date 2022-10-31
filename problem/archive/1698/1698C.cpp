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
    int n; cin >> n;
    vi a(n); in(a);

    int cnt_pos = 0, cnt_neg = 0, cnt_zero = 0;
    rep(i, n) {
        if (a[i] > 0) cnt_pos++;
        if (a[i] < 0) cnt_neg++;
        if (a[i] == 0) cnt_zero++;
        if (cnt_pos >= 3 || cnt_neg >= 3) {
            cout << "NO\n";
            return;
        }
    }

    vi b;
    if (cnt_zero > 0) b.push_back(0);
    rep(i, n) {
        if (a[i] != 0) b.push_back(a[i]);
    }

    int m = ssz(b);
    rep(i, m - 2) {
        repa(j, i + 1, m - 1) {
            repa(k, j + 1, m) {
                int cur = b[i] + b[j] + b[k];
                if (!count(b.begin(), b.end(), cur)) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}