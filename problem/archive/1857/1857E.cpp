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

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; });

    vector<ll> suf(n);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + (abs(a[idx[i]] - a[idx[i + 1]])) * 1ll * (n - 1 - i) + 1;
    }

    vector<ll> ans(n);
    ll pre = 0;
    for (int i = 0; i < n; i++) {
        if (i) {
            pre += (abs(a[idx[i]] - a[idx[i - 1]])) * 1ll * i + 1;
        }
        ans[idx[i]] = pre + suf[i] + 1;
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