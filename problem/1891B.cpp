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
    vi a(n); in(a);
    vi b(q); in(b);

    vi c, vis(31, 0);
    for (auto x: b) {
        if (!vis[x]) {
            c.push_back(x);
            vis[x] = 1;
        }
    }

    for (auto &x: a) {
        for (auto i: c) {
            int lb = x & -x;
            if (lb >= (1 << i)) {
                x |= 1 << (i - 1);
            }
        }
    }

    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}