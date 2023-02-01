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
    int n; string s;
    cin >> n >> s;

    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 0;

    int x = 0, y = 0;
    int mn = n + 1, l = 0, r = 0;
    rep(i, n) {
        auto c = s[i];
        if (c == 'L') x -= 1;
        if (c == 'R') x += 1;
        if (c == 'U') y += 1;
        if (c == 'D') y -= 1;
        if (mp.count({x, y})) {
            if (i + 1 - mp[{x, y}] < mn) {
                mn = i + 1 - mp[{x, y}];
                l = mp[{x, y}] + 1;
                r = i + 1;
            }
        }
        mp[{x, y}] = i + 1;
    }

    if (mn == n + 1) {
        cout << -1 << endl;
        return;
    }
    cout << l << " " << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}