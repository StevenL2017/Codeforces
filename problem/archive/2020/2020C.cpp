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
    ll b, c, d;
    cin >> b >> c >> d;

    // 0 0 0  0
    // 0 0 1  1
    // 0 1 0  0
    // 0 1 1  
    // 1 0 0  
    // 1 0 1  1 or 0
    // 1 1 0  1
    // 1 1 1  0

    ll a = 0;
    for (int i = 60; i >= 0; i--) {
        if (d >> i & 1) {
            if (!(b >> i & 1) && (c >> i & 1)) {
                cout << -1 << endl;
                return;
            }
            a |= ((b >> i & 1) && (c >> i & 1) ? 0 : 1ll << i);
        } else {
            if ((b >> i & 1) && !(c >> i & 1)) {
                cout << -1 << endl;
                return;
            }
            a |= ((b >> i & 1) && (c >> i & 1) ? 1ll << i : 0);
        }
    }
    cout << a << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}