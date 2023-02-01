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

    int n = ssz(s), even0 = -1, j = -1, k = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i % 2 == 0) {
                if (even0 == 0) {
                    j = k;
                }
                even0 = 1;
            } else {
                if (even0 == 1) {
                    j = k;
                }
                even0 = 0;
            }
            k = i;
        }
        else if (s[i] == '1') {
            if (i % 2 == 1) {
                if (even0 == 0) {
                    j = k;
                }
                even0 = 1;
            } else {
                if (even0 == 1) {
                    j = k;
                }
                even0 = 0;
            }
            k = i;
        }
        ans += i - j;
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