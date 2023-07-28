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

    vi b;
    for (auto x : a) {
        if (x == 0) {
            b.push_back(x);
        } else if (x == 1) {
            if (b.empty() || b.back() == 0) {
                b.push_back(x);
            }
        } else {
            while (!b.empty() && b.back() == 1) {
                b.pop_back();
            }
            if (b.empty() || b.back() == 0) {
                b.push_back(x);
            }
        }
    }

    a = b;
    n = ssz(a);

    vi twos, ones;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) twos.push_back(i);
        else if (a[i] == 1) ones.push_back(i);
    }

    vi vis(n, 0);
    for (auto i : twos) {
        vis[i] = 1;
        if (i > 0) vis[i - 1] = 1;
        if (i < n - 1) vis[i + 1] = 1;
    }
    for (auto i : ones) {
        vis[i] = 1;
        if (i > 0) {
            if (vis[i - 1] == 0) {
                vis[i - 1] = 1;
                continue;
            }
        }
        if (i < n - 1) vis[i + 1] = 1;
    }

    int cnt = 0;
    for (auto x : vis) {
        if (x == 0) cnt++;
    }

    cout << cnt + ssz(twos) + ssz(ones) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}