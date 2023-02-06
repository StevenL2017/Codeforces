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

int query(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n; cin >> n;

    vi p(n, -1);
    for (int i = 0; i + 1 < n; i += 2) {
        int p1 = i + 1, p2 = i + 2;
        int mx = query(1, p1, p2, n - 1);
        if (mx == n - 1) {
            int temp = query(1, p2, p1, n - 1);
            if (temp == n) {
                p[p1 - 1] = n;
                p[p2 - 1] = query(2, p2, p1, 1);
                continue;
            }
        }
        int val = query(1, p1, p2, mx - 1);
        if (val == mx - 1) {
            p[p1 - 1] = mx;
            p[p2 - 1] = query(2, p2, p1, 1);
        }
        else if (val == mx) {
            p[p2 - 1] = mx;
            p[p1 - 1] = query(2, p1, p2, 1);
        }
    }

    if (p.back() == -1) {
        vi vis(n, 0);
        rep(i, n - 1) {
            vis[p[i] - 1] = 1;
        }
        rep(i, n) {
            if (!vis[i]) {
                p[n - 1] = i + 1;
                break;
            }
        }
    }

    cout << "! ";
    out(p);
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}