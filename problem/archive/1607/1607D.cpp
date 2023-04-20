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
    vi a(n); in(a);
    string s; cin >> s;

    vi pre(n, 0), suf(n, 0);
    rep(i, n) {
        if (s[i] == 'R') {
            if (a[i] <= n) {
                pre[max(0, a[i] - 1)]++;
            }
        } else {
            if (a[i] >= 1) {
                suf[min(n - 1, a[i] - 1)]++;
            }
        }
    }

    int tot_pre = 0, tot_suf = 0, zero = 0;
    repd(i, n - 1, -1) {
        if (pre[i]) {
            tot_pre += min(pre[i], zero + 1);
            zero = max(0, zero - pre[i] + 1);
        } else {
            zero++;
        }
    }
    zero = 0;
    rep(i, n) {
        if (suf[i]) {
            tot_suf += min(suf[i], zero + 1);
            zero = max(0, zero - suf[i] + 1);
        } else {
            zero++;
        }
    }

    if (tot_pre + tot_suf < n) {
        cout << "NO\n";
        return;
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