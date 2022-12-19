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
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--; c--;

    vector<string> ans(n, string(n, '.'));
    repd(i, r, -1) {
        auto col = (c + r - i) % n;
        rep(j, n) {
            if (abs(j - col) % k == 0) {
                ans[i][j] = 'X';
            }
        }
    }
    repa(i, r + 1, n) {
        auto col = (c - (i - r) + n) % n;
        rep(j, n) {
            if (abs(j - col) % k == 0) {
                ans[i][j] = 'X';
            }
        }
    }

    for (auto& row: ans) cout << row << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}