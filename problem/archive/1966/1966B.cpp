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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    in(a);

    if (a[0][0] == a[n - 1][m - 1] || a[0][m - 1] == a[n - 1][0]) {
        cout << "YES\n";
        return;
    }

    if (a[0][0] == a[0][m - 1]) {
        for (int j = 1; j < m - 1; j++) {
            if (a[n - 1][j] == a[0][0] || a[0][j] == a[n - 1][m - 1]) {
                cout << "YES\n";
                return;
            }
        }
    } else {
        for (int i = 1; i < n - 1; i++) {
            if (a[i][0] == a[0][m - 1] || a[i][m - 1] == a[0][0]) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}