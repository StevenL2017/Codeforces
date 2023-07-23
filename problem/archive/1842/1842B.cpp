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
    int n, x; cin >> n >> x;
    vi a(n), b(n), c(n);
    in(a); in(b); in(c);

    int y = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] & x) == a[i]) {
            y |= a[i];
        } else {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((b[i] & x) == b[i]) {
            y |= b[i];
        } else {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((c[i] & x) == c[i]) {
            y |= c[i];
        } else {
            break;
        }
    }

    cout << (x == y ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}