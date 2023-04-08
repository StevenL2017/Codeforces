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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vi pre(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i];
        if (s[i] == '+') {
            if (i & 1) pre[i + 1]--;
            else pre[i + 1]++;
        } else {
            if (i & 1) pre[i + 1]++;
            else pre[i + 1]--;
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;

        auto tot = pre[r] - pre[l - 1];
        
        if (tot == 0) {
            cout << 0 << endl;
        } else {
            if ((r - l + 1) & 1) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}