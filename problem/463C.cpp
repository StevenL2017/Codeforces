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
    vector<vector<ll>> mat(n, vector<ll>(n));
    rep(i, n) in(mat[i]);

    map<int, ll> left, right;
    rep(i, n) {
        rep(j, n) {
            left[i + j] += mat[i][j];
            right[i - j] += mat[i][j];
        }
    }
    
    vector<vector<ll>> val(2, vector<ll>(2, -INF_LL));
    vector<vector<pair<int, int>>> idx(2, vector<pair<int, int>>(2));
    rep(i, n) {
        rep(j, n) {
            auto v = left[i + j] + right[i - j] - mat[i][j];
            if (v > val[(i + j) % 2][abs(i - j) % 2]) {
                val[(i + j) % 2][abs(i - j) % 2] = v;
                idx[(i + j) % 2][abs(i - j) % 2] = {i + 1, j + 1};
            }
        }
    }

    ll mx = -INF_LL;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    rep(i, 2) {
        rep(j, 2) {
            auto l1 = i, r1 = j, l2 = i ^ 1, r2 = j ^ 1;
            auto v = val[l1][r1] + val[l2][r2];
            if (v > mx) {
                mx = v;
                x1 = idx[l1][r1].first;
                y1 = idx[l1][r1].second;
                x2 = idx[l2][r2].first;
                y2 = idx[l2][r2].second;
            }
        }
    }

    cout << mx << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}