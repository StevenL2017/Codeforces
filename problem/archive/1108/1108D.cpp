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
    int n; string s;
    cin >> n >> s;

    int ans = 0;
    rep(i, n - 1) {
        if (s[i] != s[i + 1]) continue;
        if (s[i] == 'R') {
            if (i + 2 < n && s[i + 2] == 'G') {
                s[i + 1] = 'B';
            } else {
                s[i + 1] = 'G';
            }
        }
        else if (s[i] == 'B') {
            if (i + 2 < n && s[i + 2] == 'G') {
                s[i + 1] = 'R';
            } else {
                s[i + 1] = 'G';
            }
        }
        else {
            if (i + 2 < n && s[i + 2] == 'B') {
                s[i + 1] = 'R';
            } else {
                s[i + 1] = 'B';
            }
        }
        ans++;
    }

    cout << ans << endl << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}