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

    vector<ll> pre(1, 0);
    int x = n, c = 0;
    while (pre.back() < n) {
        if (x) {
            x >>= 1;
        }
        if ((1 + x * 2) * (1 << c) <= n) x++;
        pre.push_back(pre.back() + x);
        c++;
    }
    auto idx = lower_bound(begin(pre), end(pre), k) - begin(pre) - 1;

    cout << (1 + (k - pre[idx] - 1) * 2) * (1 << idx) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}