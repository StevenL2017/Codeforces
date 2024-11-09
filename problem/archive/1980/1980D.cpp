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
    vi a(n);
    in(a);

    vi suf(n + 1, -1);
    suf[n] = 1e9 + 7;
    for (int i = n - 1; i > 0; i--) {
        suf[i] = gcd(a[i], a[i - 1]);
        if (suf[i] > suf[i + 1]) {
            suf[i] = -1;
            break;
        }
    }

    if (suf[2] > 0) {
        cout << "YES" << endl;
        return;
    }

    int pre = 0;
    for (int i = 1; i < n - 1; i++) {
        int cur = gcd(a[i - 1], a[i + 1]);
        if (pre <= cur && cur <= suf[i + 2]) {
            cout << "YES" << endl;
            return;
        }
        cur = gcd(a[i - 1], a[i]);
        if (pre > cur) {
            pre = 0;
            break;
        }
        pre = cur;
    }

    cout << (pre ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}