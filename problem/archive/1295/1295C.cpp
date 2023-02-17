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
    string s, t;
    cin >> s >> t;

    int n = ssz(s);
    vector<vi> nxt(n + 1, vi(26, n));
    repd(i, n - 1, -1) {
        rep(j, 26) {
            nxt[i][j] = nxt[i + 1][j];
            if (j == s[i] - 'a') {
                nxt[i][j] = i;
            }
        }
    }

    int ans = 0, m = ssz(t);
    for (int i = 0, j = 0; i < m; ) {
        int pre = i;
        while (j < n && nxt[j][t[i] - 'a'] < n) {
            j = nxt[j][t[i] - 'a'] + 1;
            i++;
            if (i == m) break;
        }
        if (i == pre) {
            cout << -1 << endl;
            return;
        }
        ans++;
        j = 0;
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