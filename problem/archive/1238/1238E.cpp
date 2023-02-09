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
    string s; cin >> s;

    vector<vector<int>> cnt(m, vector<int>(m, 0));
    rep(i, n - 1) {
        if (s[i] != s[i + 1]) {
            cnt[s[i] - 'a'][s[i + 1] - 'a']++;
            cnt[s[i + 1] - 'a'][s[i] - 'a']++;
        }
    }

    int k = (1 << m);
    vector<int> f(k, INT_MAX);
    f[0] = 0;
    rep(mask, k) {
        rep(i, m) {
            if (mask >> i & 1) continue;
            int pos = __builtin_popcount(mask);
            int cnt_in = 0, cnt_out = 0;
            rep(j, m) {
                if (mask >> j & 1) {
                    cnt_in += cnt[i][j];
                } else {
                    cnt_out += cnt[i][j];
                }
            }
            f[mask | (1 << i)] = min(f[mask | (1 << i)], f[mask] + pos * (cnt_in - cnt_out));
        }
    }

    cout << f.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}