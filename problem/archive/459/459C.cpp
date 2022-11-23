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
    int n, k, d;
    cin >> n >> k >> d;

    ll s = 1;
    rep(i, d) {
        s *= k;
        if (s >= n) break;
    }
    if (s < n) {
        cout << -1 << endl;
        return;
    }

    vector<vi> a(n, vi(d, 0));
    rep(i, n) {
        if (i > 0) {
            rep(j, d) a[i][j] = a[i - 1][j];
        }
        rep(j, d) {
            a[i][j] = (a[i][j] + 1) % k;
            if (a[i][j]) break;
        }
    }
    
    rep(j, d) {
        rep(i, n) {
            cout << a[i][j] + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}