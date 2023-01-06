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
    vi a(n + 1, 0); rep(i, n) cin >> a[i + 1];

    vi pos(n + 1, n + 1), nxt(n + 1, 0);
    repd(i, n, -1) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    
    int ans = 0, x = 0, y = 0;
    repa(i, 1, n + 1) {
        if (a[x] == a[i]) {
            ans += a[y] != a[i];
            y = i;
        }
        else if (a[y] == a[i]) {
            ans += a[x] != a[i];
            x = i;
        }
        else if (nxt[x] < nxt[y]) {
            ans += a[x] != a[i];
            x = i;
        }
        else {
            ans += a[y] != a[i];
            y = i;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}