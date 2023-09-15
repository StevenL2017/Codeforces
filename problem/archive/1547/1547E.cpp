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
    int n, k;
    cin >> n >> k;
    vi a(k); in(a);
    vi b(n);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        b[a[i] - 1] = x;
    }

    vi suf(n + 1, 2e9);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = min(suf[i], suf[i + 1] + 1);
        if (b[i]) {
            suf[i] = min(suf[i], b[i]);
        }
    }

    vi ans(n, 2e9);
    int pre = 2e9;
    for (int i = 0; i < n; i++) {
        pre++;
        if (b[i]) {
            pre = min(pre, b[i]);
        }
        ans[i] = min(pre, suf[i]);
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