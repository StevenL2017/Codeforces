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
    vi a(n); in(a);
    
    vi nxt(2, 1);
    nxt[1] = 0;
    int x = 1;
    while (x <= n) {
        rep(i, x) {
            nxt.push_back(x - i - 1);
        }
        x *= 2;
    }

    vi left;
    sorta(a);
    rep(i, n + 1) {
        if (i == 0 || i == n || a[i] != a[i - 1]) {
            left.push_back(i);
        } else {
            left.push_back(left.back());
        }
    }
    
    int ans = INT_MAX, mid = 1;
    while (mid <= n) {
        rep(i, n + 1) {
            if (left[i] == i) {
                int j = left[min(n, i + mid)] - i;
                int k = n - i - j;
                ans = min(ans, nxt[i] + mid - j + nxt[k]);
            }
        }
        mid *= 2;
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