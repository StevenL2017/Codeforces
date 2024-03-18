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
    int a, b, l;
    cin >> a >> b >> l;

    int ca = 1, cb = 1, x = l, y = l;
    while (x % a == 0) {
        x /= a;
        ca++;
    }
    while (y % b == 0) {
        y /= b;
        cb++;
    }

    set<int> s;
    for (int i = 0, x = 1; i <= ca; i++, x *= a) {
        for (int j = 0, y = 1; j <= cb; j++, y *= b) {
            ll m = x * 1ll * y;
            if (l % m != 0) continue;
            s.insert(l / m);
        }
    }

    cout << ssz(s) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}