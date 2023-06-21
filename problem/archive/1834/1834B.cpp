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
    string l, r; cin >> l >> r;

    if (ssz(l) < ssz(r)) {
        cout << (int)(r[0] - '0') + 9 * (ssz(r) - 1) << endl;
        return;
    }

    for (int i = 0; i < ssz(l); i++) {
        if (l[i] != r[i]) {
            cout << (int)(r[i] - l[i]) + 9 * (ssz(r) - 1 - i) << endl;
            return;
        }
    }

    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}