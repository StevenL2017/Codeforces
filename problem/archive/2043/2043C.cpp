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

    ll pre = 0;
    ll mnl = 0, mxl = 0;
    ll mnr = 2e9, mxr = -2e9;
    ll l1 = 0, r1 = 0;
    ll l2 = 2e9, r2 = -2e9;
    for (auto x: a) {
        pre += x;
        if (abs(x) != 1) {
            mnr = mnl;
            mxr = mxl;
            mnl = mxl = pre;
        }
        l1 = min(l1, pre - mxl);
        r1 = max(r1, pre - mnl);
        l2 = min(l2, pre - mxr);
        r2 = max(r2, pre - mnr);
        mnl = min(mnl, pre);
        mxl = max(mxl, pre);
    }

    if (r1 < l2) {
        cout << max(0ll, r1 - l1 + 1) + max(0ll, r2 - l2 + 1) << endl;
        for (int x = l1; x <= r1; x++) {
            cout << x << " ";
        }
        for (int x = l2; x <= r2; x++) {
            cout << x << " ";
        }
    } else if (r2 < l1) {
        cout << max(0ll, r1 - l1 + 1) + max(0ll, r2 - l2 + 1) << endl;
        for (int x = l2; x <= r2; x++) {
            cout << x << " ";
        }
        for (int x = l1; x <= r1; x++) {
            cout << x << " ";
        }
    } else {
        ll l = min(l1, l2), r = max(r1, r2);
        cout << max(0ll, r - l + 1) << endl;
        for (int x = l; x <= r; x++) {
            cout << x << " ";
        }
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