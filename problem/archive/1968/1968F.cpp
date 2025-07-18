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
    int n, q;
    cin >> n >> q;
    vi a(n);
    in(a);

    map<int, vi> mp;
    mp[0].push_back(0);
    vi pre(n + 1);
    int xor_ = 0;
    for (int i = 0; i < n; i++) {
        xor_ ^= a[i];
        pre[i + 1] = xor_;
        mp[xor_].push_back(i + 1);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int xor_ = pre[r] ^ pre[l - 1];
        if (xor_ == 0) {
            cout << "YES" << endl;
            continue;
        }

        int left = *lower_bound(begin(mp[pre[r]]), end(mp[pre[r]]), l);
        int right = *--lower_bound(begin(mp[pre[l - 1]]), end(mp[pre[l - 1]]), r);
        cout << (left < right ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}