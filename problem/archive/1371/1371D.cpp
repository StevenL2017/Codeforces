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
    int n, k; cin >> n >> k;

    vector<string> a(n, string(n, '0'));
    int i = 0, r = 0, d = 0;
    while (i < k) {
        a[r][(r + d) % n] = '1';
        r = (r + 1) % n;
        if (r == 0) d++;
        i++;
    }

    int mxr = 0, mnr = n;
    rep(i, n) {
        int c = 0;
        rep(j, n) {
            if (a[i][j] == '1') c++;
        }
        mxr = max(mxr, c);
        mnr = min(mnr, c);
    }

    int mxc = 0, mnc = n;
    rep(j, n) {
        int c = 0;
        rep(i, n) {
            if (a[i][j] == '1') c++;
        }
        mxc = max(mxc, c);
        mnc = min(mnc, c);
    }

    cout << (mxr - mnr) * (mxr - mnr) + (mxc - mnc) * (mxc - mnc) << endl;
    rep(i, n) cout << a[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}