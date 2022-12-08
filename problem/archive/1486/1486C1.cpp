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

int interact(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;

    int s = interact(1, n), l = 1, r = n;
    if (s == n || (s > 1 && interact(1, s) == s)) {
        l = 1, r = s - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (interact(m, s) == s) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (interact(r, s) == s) {
            cout << "! " << r << endl;
        } else {
            cout << "! " << l << endl;
        }
    } else {
        l = s + 1, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (interact(s, m) == s) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (interact(s, l) == s) {
            cout << "! " << l << endl;
        } else {
            cout << "! " << r << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}