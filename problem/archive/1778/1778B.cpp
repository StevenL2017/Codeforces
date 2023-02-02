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
    int n, m, d;
    cin >> n >> m >> d;
    vi p(n), a(m); in(p); in(a);
    
    vi idx(n + 1, 0);
    rep(i, n) {
        idx[p[i]] = i + 1;
    }

    int ans = INT_MAX;
    rep(i, m - 1) {
        int p1 = idx[a[i]], p2 = idx[a[i + 1]];
        if (p1 > p2 || p2 > p1 + d) {
            cout << 0 << endl;
            return;
        }
        ans = min(ans, p2 - p1);
        if (d < n - 1) {
            ans = min(ans, d + 1 - (p2 - p1));
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}