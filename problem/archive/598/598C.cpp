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

#define M_PI 3.14159265358979323846

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;

    vector<pair<long double, int>> theta(n);
    rep(i, n) {
        theta[i] = {(long double)(atan2(a[i].second, a[i].first)), i + 1};
    }

    sorta(theta);
    long double mn = LLONG_MAX;
    int i = 0, j = 0;
    rep(k, n - 1) {
        if (theta[k + 1].first - theta[k].first < mn) {
            mn = theta[k + 1].first - theta[k].first;
            i = theta[k].second;
            j = theta[k + 1].second;
        }
    }

    if (M_PI + theta.front().first + M_PI - theta.back().first < mn) {
        i = theta.front().second;
        j = theta.back().second;
    }

    cout << i << " " << j << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}