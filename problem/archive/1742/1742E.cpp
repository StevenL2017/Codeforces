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
    int n, q; cin >> n >> q;
    vi a(n); in(a);

    vector<ll> pre(1, 0);
    vi pre_mx(1, 0);
    for (auto x : a) {
        pre.push_back(pre.back() + x);
        pre_mx.push_back(max(pre_mx.back(), x));
    }

    while (q--) {
        int x; cin >> x;

        int idx = upper_bound(pre_mx.begin(), pre_mx.end(), x) - pre_mx.begin();
        if (idx == 0) idx++;
        cout << pre[idx - 1] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}