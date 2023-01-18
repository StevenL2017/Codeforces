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
    vi p(n), c(n); in(p); in(c);

    int ans = n;
    vi vis(n, 0);
    rep(i, n) {
        if (vis[i]) continue;
        vi a;
        function<void(int)> dfs = [&] (int i) {
            vis[i] = 1;
            a.push_back(c[i]);
            if (!vis[p[i] - 1]) dfs(p[i] - 1);
        };
        dfs(i);
        repa(s, 1, ssz(a) + 1) {
            if (ssz(a) % s != 0) continue;
            rep(j, s) {
                bool ok = true;
                for (int pos = j; pos + s < ssz(a); pos += s) {
                    if (a[pos] != a[pos + s]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans = min(ans, s);
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