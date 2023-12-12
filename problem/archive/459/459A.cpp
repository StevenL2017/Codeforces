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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 || y1 == y2) {
        if (x1 == x2) {
            int d = abs(y1 - y2);
            cout << x1 + d << " " << y1 << " " << x2 + d << " " << y2 << endl;
        } else {
            int d = abs(x1 - x2);
            cout << x1 << " " << y1 + d << " " << x2 << " " << y2 + d << endl;
        }
    } else {
        if (abs(x1 - x2) != abs(y1 - y2)) {
            cout << -1 << endl;
        } else {
            cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}