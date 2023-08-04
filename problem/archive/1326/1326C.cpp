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

const int MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    vector<ll> ans(2, 0ll);
    vi idx;
    for (int i = 0; i < n; i++) {
        if (a[i] > n - k) {
            ans[0] += a[i];
            idx.push_back(i);
        }
    }

    ans[1] = 1;
    for (int i = 1; i < ssz(idx); i++) {
        ans[1] *= (idx[i] - idx[i - 1]);
        ans[1] %= MOD;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}