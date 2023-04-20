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
    vi vis(26, 0);
    rep(i, n) {
        vis[s[i] - 'a'] = 1;
    }

    int ans = n;
    rep(j, 26) {
        if (!vis[j]) continue;
        int mx = 0, i = 0;
        while (i < n) {
            while (i < n && s[i] - 'a' == j) {
                i++;
            }
            if (i == n) break;
            int i0 = i;
            while (i < n && s[i] - 'a' != j) {
                i++;
            }
            auto c = i - i0;
            repd(k, 22, -1) {
                if (c & (1 << k)) {
                    mx = max(mx, k + 1);
                    break;
                }
            }
        }
        ans = min(ans, mx);
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