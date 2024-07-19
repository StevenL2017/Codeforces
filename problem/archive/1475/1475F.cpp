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
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    in(a);
    in(b);

    for (int i = 0; i < n; i++) {
        if (a[0][i] == '1') {
            for (int j = 0; j < n; j++) {
                a[j][i] ^= '0' ^ '1';
            }
        }
        if (b[0][i] == '1') {
            for (int j = 0; j < n; j++) {
                b[j][i] ^= '0' ^ '1';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i][0] == '1') {
            for (int j = 0; j < n; j++) {
                a[i][j] ^= '0' ^ '1';
            }
        }
        if (b[i][0] == '1') {
            for (int j = 0; j < n; j++) {
                b[i][j] ^= '0' ^ '1';
            }
        }
    }

    cout << (a == b ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}