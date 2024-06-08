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
    int n; cin >> n;
    vi a(n); in(a);

    set<int> s, z, v;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            z.insert(i + 1);
            continue;
        }
        s.erase(a[i]);
    }

    for (auto x : s) {
        if (!z.count(x)) continue;
        int mn = -1;
        for (auto y : z) {
            if (y == x) continue;
            mn = y;
            break;
        }
        a[mn - 1] = x;
        z.erase(mn);
        v.insert(x);
    }
    for (auto x : s) {
        if (v.count(x)) continue;
        int mn = *z.begin();
        a[mn - 1] = x;
        z.erase(mn);
    }

    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}