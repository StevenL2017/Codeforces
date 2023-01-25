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
    vector<vi> a(n, vi(m));
    rep(i, n) in(a[i]);

    map<string, int> mp;
    for (auto& p: a) {
        vi idx(m, -1);
        rep(i, m) {
            idx[p[i] - 1] = i;
        }
        string s;
        rep(i, m) {
            s += (char)(idx[i] + '0');
            mp[s] = max(mp[s], i + 1);
        }
    }

    vi ans(n, 0);
    rep(i, n) {
        string s;
        rep(j, m) {
            s += (char)((a[i][j] - 1) + '0');
            ans[i] = max(ans[i], mp[s]);
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}