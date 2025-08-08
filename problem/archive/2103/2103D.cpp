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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);

    int mx = *max_element(begin(a), end(a)) + 1;
    for (auto &x: a) {
        if (x == -1) {
            x = mx;
        }
    }

    vi ans(n);
    int l = 1, r = n;
    for (int k = 1; k <= mx; k++) {
        int suf = n - 1;
        while (suf >= 0 && a[suf] <= k) {
            suf--;
        }
        for (int i = 0; i <= suf; i++) {
            if (a[i] != k) {
                continue;
            }
            ans[i] = (k & 1 ? r--: l++);
        }
        for (int i = n - 1; i > suf; i--) {
            if (a[i] != k) {
                continue;
            }
            ans[i] = (k & 1 ? r--: l++);
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