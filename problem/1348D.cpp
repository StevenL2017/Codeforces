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
const ll  INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;

    int d = 31;
    repd(i, 31, -1) {
        if (n & (1 << i)) {
            d = i;
            break;
        }
    }

    vi a(d, 0);
    int diff = n - (1 << d);
    repa(i, 1, d) {
        int cur = pow(2, i - 1);
        a[i] = cur;
        int delta = min(cur, diff);
        a[i - 1] += delta;
        a[i] -= delta;
        diff -= delta;
    }
    a[d - 1] += diff;

    cout << d << endl;
    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}