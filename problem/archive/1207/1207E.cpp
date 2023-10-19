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

int query(vi& a) {
    cout << "? ";
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    vi a(100), b(100);
    iota(a.begin(), a.end(), 1);
    iota(b.begin(), b.end(), 1);
    for (int i = 0; i < 100; i++) {
        b[i] <<= 7;
    }

    int x = query(a), y = query(b);
    int ans = 0;
    ans |= x & (((1 << 7) - 1) << 7);
    ans |= y & ((1 << 7) - 1);
    cout << "! " << ans << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}