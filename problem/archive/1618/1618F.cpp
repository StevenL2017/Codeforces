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
    ll x, y;
    cin >> x >> y;

    string a, b;
    while (x) {
        a += (x & 1) + '0';
        x >>= 1;
    }
    while (y) {
        b += (y & 1) + '0';
        y >>= 1;
    }

    if (a == b) {
        cout << "YES" << endl;
        return;
    }

    int i = 0;
    while (i < ssz(a) && a[i] == '0') {
        i++;
    }
    reverse(a.begin(), a.end());
    string a1 = a.substr(0, ssz(a) - i);

    for (auto s: {a + '1', a1}) {
        string sr = s;
        reverse(sr.begin(), sr.end());
        for (int i = 0; i < ssz(b) - ssz(s) + 1; i++) {
            int j = ssz(b) - ssz(s) - i;
            string cur = string(i, '1') + s + string(j, '1');
            string cur_rev = string(i, '1') + sr + string(j, '1');
            if (cur == b || cur_rev == b) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}