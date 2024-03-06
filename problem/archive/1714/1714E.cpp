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

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            a[i] += a[i] % 10;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 10 == 0) {
            for (int j = 0; j < n; j++) {
                if (a[j] != a[i]) {
                    cout << "No\n";
                    return;
                }
            }
            cout << "Yes\n";
            return;
        }
        while (a[i] % 10 != 2) {
            a[i] += a[i] % 10;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] % 20 != a[0] % 20) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}