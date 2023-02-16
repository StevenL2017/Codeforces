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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    int first = 0;
    rep(i, n - 1) {
        if (s[i] == s[i + 1]) {
            first = i + 1;
            break;
        }
    }

    if (first > 0) {
        string ss = s.substr(first, n);
        reverse(ss.begin(), ss.end());
        string temp = t + ss;
        rep(i, ssz(temp) - 1) {
            if (temp[i] == temp[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
    }

    int second = 0;
    rep(i, m - 1) {
        if (t[i] == t[i + 1]) {
            second = i + 1;
            break;
        }
    }

    if (second > 0) {
        string tt = t.substr(second, m);
        reverse(tt.begin(), tt.end());
        string temp = s + tt;
        rep(i, ssz(temp) - 1) {
            if (temp[i] == temp[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}