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

int query(int r, int c) {
    cout << "? " << r << " " << c << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n, m; cin >> n >> m;

    int r, c;
    auto d1 = query(1, 1);
    if (n >= m) {
        int tr = d1 + 1;
        auto d2 = query(tr, 1);
        int tc = d2 + 1;
        auto d3 = query(tr, tc);
        if (d3 == 0) {
            r = tr;
            c = tc;
        } else {
            c = d1 + 1;
            r = tr - d3;
        }
    } else {
        int tc = d1 + 1;
        auto d2 = query(1, tc);
        int tr = d2 + 1;
        auto d3 = query(tr, tc);
        if (d3 == 0) {
            r = tr;
            c = tc;
        } else {
            r = d1 + 1;
            c = tc - d3;
        }
    }

    cout << "! " << r << " " << c << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}