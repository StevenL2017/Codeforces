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
    long double a, b, c;
    cin >> a >> b >> c;

    cout.precision(10);

    if (a == 0 && b == 0) {
        if (c == 0) cout << -1 << endl;
        else cout << 0 << endl;
        return;
    }

    if (a == 0) {
        cout << 1 << endl << -c / b << endl;
        return;
    }

    if (b == 0) {
        if (c <= 0) cout << 1 << endl << sqrt(-c / a) << endl;
        else cout << 0 << endl;
        return;
    }

    if (b * b < 4 * a * c) {
        cout << 0 << endl;
        return;
    }

    auto s = sqrt(b * b - 4 * a * c);
    if (b * b == 4 * a * c) {
        cout << 1 << endl << -b / (2 * a) << endl;
        return;
    }

    auto a1 = (-b - s) / (2 * a);
    auto a2 = (-b + s) / (2 * a);
    cout << 2 << endl;
    cout << min(a1, a2) << endl;
    cout << max(a1, a2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}