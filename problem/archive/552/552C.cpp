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
    int w, m;
    cin >> w >> m;

    vi a;
    while (m) {
        a.push_back(m % w);
        m /= w;
    }

    int n = ssz(a);
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && a[i] != 1 && a[i] != w - 1 && a[i] != w) {
            cout << "NO\n";
            return;
        }
        if (a[i] == w - 1 || a[i] == w) {
            if (i + 1 < n) a[i + 1]++;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}