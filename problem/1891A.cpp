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

int high(int x) {
    for (int i = 20; i >= 0; i--) {
        if (x >> i & 1) {
            return i;
        }
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            int h1 = high(i + 1), h2 = high(i + 2);
            if (i + 1 > (1 << h1) && (i + 2 <= (1 << h2) || h1 == h2)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}