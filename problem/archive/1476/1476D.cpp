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
    string s;
    cin >> s;

    vi pre(n, 1), suf(n, 1);
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            pre[i] = pre[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] != s[i + 1]) {
            suf[i] = suf[i + 1] + 1;
        }
    }

    vi ans(n + 1, 1);
    for (int i = 0; i <= n; i++) {
        if (i > 0 && s[i - 1] == 'L') {
            ans[i] += pre[i - 1];
        }
        if (i < n && s[i] == 'R') {
            ans[i] += suf[i];
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