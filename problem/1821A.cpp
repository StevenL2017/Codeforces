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
    string s; cin >> s;

    int n = ssz(s);
    if (n == 1) {
        if (s[0] == '?') {
            cout << 9 << endl;
            return;
        } else {
            cout << (s[0] == '0' ? 0 : 1) << endl;
            return;
        }
    }

    if (s[0] == '0') {
        cout << 0 << endl;
        return;
    }

    int ans = 1;
    if (s[0] == '?') {
        ans *= 9;
        repa(i, 1, n) {
            if (s[i] == '?') {
                ans *= 10;
            }
        }
    } else {
        rep(i, n) {
            if (s[i] == '?') {
                ans *= 10;
            }
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