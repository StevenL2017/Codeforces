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
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;

    int n = ssz(s), x = 0;
    bool ok = false;
    vi left(n, 0);
    for (int i = 0; i < n; i++) {
        x *= 10;
        x += s[i] - '0';
        if (x) ok = true;
        if (ok && x % a == 0) {
            left[i] = 1;
        }
        x %= a;
    }

    int ten = 1;
    x = 0;
    vi right(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        x += ten * (s[i] - '0');
        if (s[i] != '0' && x % b == 0) {
            right[i] = 1;
        }
        x %= b;
        ten *= 10;
        ten %= b;
    }

    for (int i = 0; i < n - 1; i++) {
        if (left[i] && right[i + 1]) {
            cout << "YES\n";
            cout << s.substr(0, i + 1) << endl << s.substr(i + 1, n - i - 1) << endl;
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}