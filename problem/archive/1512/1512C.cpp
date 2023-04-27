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
    int a, b; cin >> a >> b;
    string s; cin >> s;

    int n = a + b;
    rep(i, (n + 1) / 2) {
        if (s[i] != '?') {
            if (s[n - 1 - i] == '?') {
                s[n - 1 - i] = s[i];
            } else {
                if (s[i] != s[n - 1 - i]) {
                    cout << -1 << endl;
                    return;
                }
            }
            if (s[i] == '0') a -= 1 + (i != n - 1 - i);
            else b -= 1 + (i != n - 1 - i);
        } else {
            if (s[n - 1 - i] != '?') {
                s[i] = s[n - 1 - i];
                if (s[i] == '0') a -= 1 + (i != n - 1 - i);
                else b -= 1 + (i != n - 1 - i);
            }
        }
    }

    if (a < 0 || b < 0) {
        cout << -1 << endl;
        return;
    }

    rep(i, (n + 1) / 2) {
        if (s[i] == '?') {
            if (a > 1 && i != n - 1 - i) {
                s[i] = s[n - 1 - i] = '0';
                a -= 1 + (i != n - 1 - i);
            }
            else if (a && i == n - 1 - i) {
                s[i] = '0';
                a--;
            }
            else if (b > 1 && i != n - 1 - i) {
                s[i] = s[n - 1 - i] = '1';
                b -= 1 + (i != n - 1 - i);
            }
            else if (b && i == n - 1 - i) {
                s[i] = '1';
                b--;
            }
            else {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}