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
    int a, b, c;
    cin >> a >> b >> c;

    int res = INF;
    int ra = a, rb = b, rc = c;
    repa(x, 1, 2 * a + 1) {
        int ca = abs(x - a);
        for (int y = x; y <= 2 * b; y += x) {
            int cb = abs(y - b);
            int cc = INF, tc = c;
            if (c < y) {
                cc = abs(y - c);
                tc = y;
            }
            if (c >= y && abs((c / y) * y - c) < cc) {
                cc = abs((c / y) * y - c);
                tc = (c / y) * y;
            }
            if (c >= y && abs((c / y + 1) * y - c) < cc) {
                cc = abs((c / y + 1) * y - c);
                tc = (c / y + 1) * y;
            }

            if (ca + cb + cc < res) {
                res = ca + cb + cc;
                ra = x, rb = y, rc = tc;
            }
        }
    }

    cout << res << endl;
    cout << ra << " " << rb << " " << rc << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}