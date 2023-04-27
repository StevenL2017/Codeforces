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
    int n; cin >> n;

    vector<vi> ans(2, vi(n));
    ans[0][0] = 2 * n;
    for (int j = n - 2, v = 2 * n - 2; j > 0; j -= 2) {
        ans[0][j] = v;
        v -= 2;
    }
    for (int j = 1, v = 2; j < n; j += 2) {
        ans[0][j] = v;
        v += 2;
    }
    for (int j = 0, v = 1; j < n; j += 2) {
        ans[1][j] = v;
        v += 2;
    }
    for (int j = n - 1, v = 2 * n - 1; j >= 0; j -= 2) {
        ans[1][j] = v;
        v -= 2;
    }

    out(ans[0]);
    out(ans[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}