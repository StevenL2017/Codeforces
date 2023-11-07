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

    map<int, vi> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }
    int cnt = 0, mx = 0;
    for (auto [k, v]: mp) {
        if (ssz(v) > 1) {
            cnt++;
            mx = k;
        }
    }
    if (cnt < 2) {
        cout << -1 << endl;
        return;
    }

    vi b(n);
    for (auto [k, v]: mp) {
        b[v[0]] = 1;
        if (ssz(v) < 2) {
            continue;
        }
        for (int i = 1; i < ssz(v); i++) {
            if (k != mx) b[v[i]] = 2;
            else b[v[i]] = 3;
        }
    }
    out(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}