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
    ll n, m; cin >> n >> m;

    auto x = n;
    int cnt2 = 0, cnt5 = 0;
    while (x % 2 == 0) {
        cnt2++;
        x /= 2;
    }
    while (x % 5 == 0) {
        cnt5++;
        x /= 5;
    }

    ll k = 1;
    while (cnt2 < cnt5) {
        if (k * 2 <= m) {
            k *= 2;
            cnt2++;
        } else {
            break;
        }
    }
    while (cnt2 > cnt5) {
        if (k * 5 <= m) {
            k *= 5;
            cnt5++;
        } else {
            break;
        }
    }
    while (k * 10 <= m) {
        k *= 10;
        cnt2++;
        cnt5++;
    }
    k *= m / k;

    if (cnt2 > 0 && cnt5 > 0) cout << n * k << endl;
    else cout << n * m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}