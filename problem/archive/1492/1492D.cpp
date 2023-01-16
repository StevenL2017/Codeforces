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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    if (a == 0) {
        if (k != 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            cout << string(b, '1') << endl;
            cout << string(b, '1') << endl;
        }
        return;
    }

    if (b == 1) {
        if (k != 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            cout << '1' + string(a, '0') << endl;
            cout << '1' + string(a, '0') << endl;
        }
        return;
    }

    if (k == 0) {
        cout << "Yes\n";
        cout << string(b, '1') + string(a, '0') << endl;
        cout << string(b, '1') + string(a, '0') << endl;
        return;
    }

    if (a + b - 2 < k) {
        cout << "No\n";
        return;
    }

    string x(1, '1'), y(1, '1');
    x += '1'; y += '0';
    a--; b -= 2;
    int m = min(a, k - 1);
    rep(i, k - 1 - m) {
        x += '1';
        y += '1';
        b--;
    }
    rep(i, m) {
        x += '0';
        y += '0';
        a--;
    }
    x += '0'; y += '1';
    rep(i, b) {
        x += '1';
        y += '1';
    }
    rep(i, a) {
        x += '0';
        y += '0';
    }
    cout << "Yes\n" << x << endl << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}